#!/bin/bash

# Directorio con los ejecutables
BINDIR="bin"



for file in "$BINDIR"/*; do
    
    echo "Ejecucion $file:"
    ./"$file"
    echo ""
    
done

# Fin del script