// --- Authentication Routes ---
// This file handles the login logic.

const express = require('express');
const router = express.Router();

// Static credentials for demonstration.
// In a real application, you would check these against a database.
const ADMIN_USERNAME = 'admin';
const ADMIN_PASSWORD = 'admin';

/**
 * @route   POST /api/login
 * @desc    Authenticate a user
 * @access  Public
 */
router.post('/login', (req, res) => {
    const { username, password } = req.body;

    console.log(`Login attempt with username: ${username}`);

    if (username === ADMIN_USERNAME && password === ADMIN_PASSWORD) {
        // Successful login
        res.json({ success: true, message: 'Login successful' });
    } else {
        // Failed login
        // Send a 401 Unauthorized status code
        res.status(401).json({ success: false, message: 'Invalid credentials' });
    }
});

module.exports = router;
