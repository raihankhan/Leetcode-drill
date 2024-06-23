const puppeteer = require('puppeteer');
const axios = require('axios');
const fs = require('fs');
const { encrypt } = require('node-rsa-secrets'); // Add this package as a dependency

const email = process.env.LEETCODE_EMAIL;
const password = process.env.LEETCODE_PASSWORD;
const githubToken = process.env.GITHUB_TOKEN;

// Function to update GitHub secrets
async function updateGitHubSecret(secretName, secretValue) {
    const token = githubToken;
    const [owner, repo] = process.env.GITHUB_REPOSITORY.split('/'); // Get owner and repository name from environment variable

    const url = `https://api.github.com/repos/${owner}/${repo}/actions/secrets/${secretName}`;

    const publicKeyResponse = await axios.get(`${url}/public-key`, {
        headers: {
            Authorization: `token ${token}`,
            Accept: 'application/vnd.github+json',
        },
    });

    const { key_id: keyId, key: publicKey } = publicKeyResponse.data;

    // Encrypt the secret value using the public key
    const encryptedValue = encrypt(secretValue, publicKey);

    // Update the secret
    await axios.put(
        url,
        {
            encrypted_value: encryptedValue,
            key_id: keyId,
        },
        {
            headers: {
                Authorization: `token ${token}`,
                Accept: 'application/vnd.github+json',
            },
        }
    );
}

(async () => {
    const browser = await puppeteer.launch();
    const page = await browser.newPage();

    // Navigate to LeetCode login page
    await page.goto('https://leetcode.com/accounts/login/');

    // Fill in the email and password fields
    await page.type('#id_login', email);
    await page.type('#id_password', password);

    // Click on the submit button
    await Promise.all([
        page.waitForNavigation(),
        page.click('button[type="submit"]'),
    ]);

    // Get the CSRF token and session cookie
    const csrfToken = (await page.cookies()).find(cookie => cookie.name === 'csrftoken').value;
    const session = (await page.cookies()).find(cookie => cookie.name === 'LEETCODE_SESSION').value;

    console.log('CSRF Token:', csrfToken);
    console.log('Session:', session);

    // Update GitHub secrets with new CSRF token and session values
    await updateGitHubSecret('LEETCODE_CSRF_TOKEN', csrfToken);
    await updateGitHubSecret('LEETCODE_SESSION', session);

    await browser.close();
})();