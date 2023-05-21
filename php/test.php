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

function get($key) {
    $command = "./key_value_store get " . escapeshellarg($key);
    exec($command, $output, $return_code);

    if ($return_code === 0 && !empty($output)) {
        echo "Value for key '$key': " . $output[0] . "\n";
    } else {
        echo "Entry with key '$key' not found\n";
    }
}

put("name", "Gerald");
put("age", "18");

get("name");
get("job");

?>
