// --- Room Data Routes ---
// This file provides the room data, simulating a database.

const express = require('express');
const router = express.Router();

// The same room data from your original HTML file.
// In a real application, this would come from a database (like MongoDB or PostgreSQL).
const roomsData = [
    {
        id: 103,
        name: "Room 103 (Lecture Hall)",
        available: true,
        capacity: 80,
        features: ["Projector", "AC", "WiFi", "Sound System"],
        contact: "Contact Engr. Dela Cruz at ext. 301 for bookings.",
        imageUrl: "https://images.unsplash.com/photo-1628151020054-07d4b476e339?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D",
        bookings: [
            { time: "8:00 AM - 10:00 AM", status: "Booked (Dr. Cruz)" },
            { time: "10:00 AM - 12:00 PM", status: "Open" },
            { time: "1:00 PM - 3:00 PM", status: "Booked (CS 101)" }
        ]
    },
    {
        id: 104,
        name: "Room 104 (Lab 1)",
        available: false,
        capacity: 40,
        features: ["20 Workstations", "Linux OS", "Ethernet Ports", "Whiteboard"],
        contact: "Contact Ms. Perez at ext. 302 for technical assistance.",
        imageUrl: "https://images.unsplash.com/photo-1542831371-29b0f74f9713?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D",
        bookings: [
            { time: "10:00 AM - 12:00 PM", status: "Booked (CS 201)" },
            { time: "1:00 PM - 3:00 PM", status: "Booked (CS 202)" }
        ]
    },
    {
        id: 105,
        name: "Room 105 (Seminar)",
        available: true,
        capacity: 50,
        features: ["Video Conferencing", "Adjustable Seating", "High Speed WiFi"],
        contact: "Contact the DCST Secretary at ext. 305.",
        imageUrl: "https://images.unsplash.com/photo-1557804506-669f9829f7f4?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D",
        bookings: [
            { time: "9:00 AM - 11:00 AM", status: "Open" },
            { time: "11:00 AM - 1:00 PM", status: "Booked (Dr. Santos)" }
        ]
    },
    {
        id: 106,
        name: "Room 106 (Lab 2)",
        available: true,
        capacity: 40,
        features: ["20 Workstations", "Windows OS", "4K Monitor", "HVAC"],
        contact: "Contact Engr. Dela Cruz at ext. 301 for bookings.",
        imageUrl: "https://images.unsplash.com/photo-1596495578051-a92c3032506e?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D",
        bookings: [
            { time: "2:00 PM - 4:00 PM", status: "Open" },
            { time: "4:00 PM - 6:00 PM", status: "Open" }
        ]
    },
    {
        id: 107,
        name: "Room 107 (Discussion)",
        available: false,
        capacity: 15,
        features: ["Comfortable Seating", "Large Display Screen", "Sound Proofing"],
        contact: "Contact Ms. Perez at ext. 302 for assistance.",
        imageUrl: "https://images.unsplash.com/photo-1555431664-90a612052136?q=80&w=2670&auto=format&fit=crop&ixlib=rb-4.0.3&ixid=M3wxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8fA%3D%3D",
        bookings: [
            { time: "9:00 AM - 11:00 AM", status: "Booked (Dr. Reyes)" },
            { time: "11:00 AM - 1:00 PM", status: "Booked (CS 305)" }
        ]
    },
];


/**
 * @route   GET /api/rooms
 * @desc    Get all rooms
 * @access  Public
 */
router.get('/rooms', (req, res) => {
    // Send the list of all rooms as a JSON response.
    res.json(roomsData);
});

/**
 * @route   GET /api/rooms/:id
 * @desc    Get a single room by its ID
 * @access  Public
 */
router.get('/rooms/:id', (req, res) => {
    // Find the room with the matching ID from the request parameters.
    const room = roomsData.find(r => r.id === parseInt(req.params.id));
    if (room) {
        res.json(room);
    } else {
        // If no room is found, send a 404 Not Found status.
        res.status(404).json({ message: 'Room not found' });
    }
});


module.exports = router;
