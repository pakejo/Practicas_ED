#!/bin/csh

@ inicio = 100
@ fin = 30000
@ incremento = 500

@ i = $inicio
echo > tiempos.dat

while ( $i <= $fin )
    echo Ejecución tam = $i
    echo `./ordenacion $i` >> tiempos3.dat
    @ i += $incremento
end

