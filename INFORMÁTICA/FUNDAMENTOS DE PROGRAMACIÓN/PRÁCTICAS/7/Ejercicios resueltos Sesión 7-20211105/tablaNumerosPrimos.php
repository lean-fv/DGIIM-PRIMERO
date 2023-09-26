<!-- Mostrar en pantalla una tabla de 10 por 10 con los números del 1 al 100. -->
<!DOCTYPE html>
<html>
<head>
	<title>Ejercicio</title>
</head>
<body>
    <table border=2px black style="table-layout: auto">
            <?php 
                    for ($fila=1; $fila <= 10; $fila++) { 
                            echo "<tr>";
                            for ($columna=1; $columna <= 10; $columna++) { 
                                    echo "<th>";
                                            echo (($fila -1) * 10) + $columna;
                                    echo "</th>";
                            }
                            echo "</tr>";
                    }
            ?>
     </table>

</body>
</html>

<!--Criba de Eratóstenes -->

<?php

            echo '-------------------------------------------------';

$esPrimo = array();

for ($index = 0; $index < 101; $index++) {
    
    array_push($esPrimo, TRUE);
    
}


echo '<br>';
echo 'Números primos por la criba de Eratóstenes<br>';
echo '<br>';



for ($index = 2; $index < 51; $index++) {
    
    if ($esPrimo[$index] == TRUE) {
        
        $n = 2;
        while ($index*$n < 101) {
            
            $esPrimo[$index*$n] = FALSE;
            $n++;
            
        }
        
    }
    
}

//var_dump($esPrimo);

?>

    <table border=2px black style="table-layout: auto">
            <?php 
                    for ($fila=1; $fila <= 10; $fila++) { 
                            echo "<tr>";
                            for ($columna=1; $columna <= 10; $columna++) {
                                $num = (($fila -1) * 10) + $columna;
                                if ($esPrimo[$num] == TRUE) {
                                    echo '<th style="color:green;">'.$num.'</th>';
                                } else {
                                    echo '<th style="color:red;">'.$num.'</th>'; 
                                }
                            }
                            echo "</tr>";
                    }
            ?>
     </table>