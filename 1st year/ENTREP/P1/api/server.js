// --- Main Server File ---
// This file sets up the Express server and defines the API routes.

const express = require('express');
const cors = require('cors'); // Middleware to allow cross-origin requests

const authRoutes = require('./api/auth');
const roomRoutes = require('./api/rooms');

const app = express();
const PORT = process.env.PORT || 3001; // The port the server will run on

// --- Middleware ---
// Enable CORS for all routes, allowing your HTML file to fetch data from this server.
app.use(cors());
// Enable the server to parse JSON-formatted request bodies.
app.use(express.json());

// --- API Routes ---
// Mount the authentication and room routes.
app.use('/api', authRoutes);
app.use('/api', roomRoutes);

// --- Start the Server ---
app.listen(PORT, () => {
  console.log(`✅ DCST Booking server is running on http://localhost:${PORT}`);
});
