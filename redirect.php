<?php
$host = "localhost";
$user = "root";
$pass = "";
$dbname = "url_shortener";

// Connect to DB
$conn = new mysqli($host, $user, $pass, $dbname);

if (isset($_GET['code'])) {
    $code = $_GET['code'];

    // Get long URL
    $stmt = $conn->prepare("SELECT long_url FROM urls WHERE short_code = ?");
    $stmt->bind_param("s", $code);
    $stmt->execute();
    $stmt->bind_result($long_url);

    if ($stmt->fetch()) {
        header("Location: " . $long_url);
        exit();
    } else {
        echo "URL not found!";
    }

    $stmt->close();
}
$conn->close();
?>
