<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Passenger Management</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: rgb(249, 224, 3);
            margin: 0;
            padding: 20px;
        }
        h1, h3 {
            text-align: center;
            color: #333;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            background-color: white;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
        }
        form {
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin: 10px 0 5px;
            font-weight: bold;
        }
        input[type="text"], input[type="submit"] {
            width: 100%;
            padding: 10px;
            margin: 5px 0 15px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        input[type="submit"] {
            background-color: #007bff;
            color: white;
            border: none;
            cursor: pointer;
        }
        input[type="submit"]:hover {
            background-color: #0056b3;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
        }
        th, td {
            padding: 10px;
            border: 1px solid #ddd;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
        .alert {
            padding: 10px;
            background-color: #f44336;
            color: white;
            margin-bottom: 20px;
            display: none;
        }
        .success {
            background-color: #4CAF50;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1></h1>
        
        <?php
        $host = "localhost";
        $username = "root";
        $password = "";
        $dbname = "airline_management_system";
        $con = mysqli_connect($host, $username, $password, $dbname);
        
        if (!$con) {
            die("Connection failed: " . mysqli_connect_error());
        }

        if (isset($_POST['insert_submit'])) {
            $p_id = $_POST['p_id'] ?? '';
            $p_name = $_POST['p_name'] ?? '';
            $ddestination = $_POST['ddestination'] ?? '';
            $adestination = $_POST['adestination'] ?? '';

            $sql = "INSERT INTO passenger(p_id, p_name, departure_destination, arrival_destination) VALUES ('$p_id', '$p_name', '$ddestination', '$adestination')";
            $rs = mysqli_query($con, $sql);
            echo "<div class='alert " . ($rs ? "success" : "") . "'>" . ($rs ? "Entries added!" : "Error: " . mysqli_connect_error($con)) . "</div>";
        }

        if (isset($_POST['update_submit'])) {
            $up_id = $_POST['up_id'] ?? '';
            $p_name = $_POST['p_name'] ?? '';
            $ddestination = $_POST['ddestination'] ?? '';
            $adestination = $_POST['adestination'] ?? '';

            $sqlu = "UPDATE passenger SET p_name='$p_name', departure_destination='$ddestination', arrival_destination='$adestination' WHERE p_id='$up_id'";
            $rs = mysqli_query($con, $sqlu);
            echo "<div class='alert " . ($rs ? "success" : "") . "'>" . ($rs ? "Entries updated!" : "Error: " . mysqli_connect_error($con)) . "</div>";
            if ($rs) {
                echo '<form method="POST" action="">
                        <label for="confirm_delete">Do you want to delete this passenger information? (yes/no)</label>
                        <input type="text" name="delete_option" id="confirm_delete" required>
                        <input type="submit" name="confirm_delete" value="Submit">
                      </form>';
            }
           
        }

        if (isset($_POST['confirm_delete'])) {
            if (strtolower($_POST['delete_option']) === 'yes') {
                echo '<h3>Delete Record</h3>
                      <form method="POST" action="">
                          <label for="delete_id">Enter the Passenger ID to delete:</label>
                          <input type="text" name="delete_id" id="delete_id" required>
                          <input type="submit" name="delete_submit" value="Delete">
                      </form>';
            } elseif (strtolower($_POST['delete_option']) === 'no') {
                echo "<div class='alert'>No record will be deleted.<br></div>";
            }
        }

        if (isset($_POST['delete_submit'])) {
            $delete_id = $_POST['delete_id'] ?? '';
            $sql_delete = "DELETE FROM passenger WHERE p_id='$delete_id'";
            $rs = mysqli_query($con, $sql_delete);
            echo "<div class='alert " . ($rs ? "success" : "") . "'>" . ($rs ? "Record deleted successfully!" : "Error: " . mysqli_error($con)) . "</div>";
        }
        $sql_view = "SELECT * FROM passenger";
        $result = mysqli_query($con, $sql_view);
        if (mysqli_num_rows($result) > 0) {
            echo "<h3>Passenger Records:</h3>
                  <table>
                      <tr>
                          <th>Passenger ID</th>
                          <th>Name</th>
                          <th>Departure Destination</th>
                          <th>Arrival Destination</th>
                      </tr>";
            while ($row = mysqli_fetch_assoc($result)) {
                echo "<tr>
                          <td>{$row['P_ID']}</td>
                          <td>{$row['P_Name']}</td>
                          <td>{$row['departure_destination']}</td>
                          <td>{$row['arrival_destination']}</td>
                      </tr>";
            }
            echo "</table>";
        } else {
            echo "<div class='alert'>No records found.</div>";
        }
        mysqli_close($con);
        ?>
        <h3>Update Passenger Info</h3>
        <form method='POST' action=''>
            <label for="up_id">Enter the Passenger ID to Update</label>
            <input type="text" name="up_id" id="up_id" required>
            <label for="p_name">Passenger Name</label>
            <input type="text" name="p_name" id="p_name">
            <label for="ddestination">Departure Destination</label>
            <input type="text" name="ddestination" id="ddestination">
            <label for="adestination">Arrival Destination</label>
            <input type="text" name="adestination" id="adestination">
            <input type="submit" name="update_submit" id="update_submit" value="Update">
        </form>
    </div>
</body>
</html>