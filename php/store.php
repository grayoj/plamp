<?php

function put($key, $value) {
    $command = "./store put " . escapeshellarg($key) . " " . escapeshellarg($value);
    exec($command, $output, $return_code);

    if ($return_code === 0) {
        echo "Added entry with key '$key' and value '$value'\n";
    } else {
        echo "Failed to add entry\n";
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $key = $_POST['key'];
    $value = $_POST['value'];

    if (!empty($key) && !empty($value)) {
        put($key, $value);
    }
}

?>

<!DOCTYPE html>
<html>
<head>
    <title>Plamp Store</title>
</head>
<body>
    <h1>Try and store something.</h1>
    <form method="POST" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label for="key">Key:</label>
        <input type="text" name="key" id="key" required><br>

        <label for="value">Value:</label>
        <input type="text" name="value" id="value" required><br>

        <input type="submit" value="Submit">
    </form>
</body>
</html>




