# URL Shortener (C++ + PHP + MySQL)

A simple URL shortener app where:
- C++ is used to generate short codes and send data via HTTP.
- PHP stores and retrieves data from MySQL.
- MySQL stores URL mappings.

---

## 🔧 Setup Instructions

### 1. Database Setup
sql
-- Run this in phpMyAdmin or MySQL CLI
CREATE DATABASE IF NOT EXISTS url_shortener;
USE url_shortener;

CREATE TABLE IF NOT EXISTS urls (
    id INT AUTO_INCREMENT PRIMARY KEY,
    long_url TEXT NOT NULL,
    short_code VARCHAR(10) NOT NULL UNIQUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);


### 2. PHP Backend Files
- Place `store.php` and `redirect.php` inside `htdocs/url-shortner/` folder in XAMPP.

### 3. C++ Code
- Compile and run `shortener.cpp` using a C++ compiler (e.g., g++ or MinGW).
- This file:
  - Takes long URL input
  - Generates short code
  - Sends it to PHP server
  - Displays short URL

### 4. Run the Project
- Start Apache and MySQL via XAMPP
- Run the C++ program to generate and store a new short link
- Open the short URL in a browser:  
  `http://localhost/url-shortner/redirect.php?code=abc123`

---

## 📂 File Structure

url-shortener-project/
├── shortener.cpp
├── store.php
├── redirect.php
├── urls.sql
└── README.md


---

## ✨ Example
**Input:**

Enter long URL: https://www.instagram.com/anjalliii_23

**Output:**

Short URL: http://localhost/url-shortner/redirect.php?code=xYz12A
