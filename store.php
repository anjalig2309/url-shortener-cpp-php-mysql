<?php
$host = "localhost";
$user = "root";
$pass = "";
$dbname = "url_shortener";

// Connect to MySQL
$conn = new mysqli($host, $user, $pass, $dbname);

// If POST request
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $long_url = $_POST["long_url"];
    $short_code = $_POST["short_code"];

    // Insert data
    $stmt = $conn->prepare("INSERT INTO urls (long_url, short_code) VALUES (?, ?)");
    $stmt->bind_param("ss", $long_url, $short_code);

    if ($stmt->execute()) {
        echo "URL saved successfully!";
    } else {
        echo "Error: " . $conn->error;
    }

    $stmt->close();
}
$conn->close();
?>
