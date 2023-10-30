#!/bin/bash

# Solicitar el nombre del archivo al usuario
read -p "Ingrese el nombre del archivo: " nombre_archivo

archivo_comprimido="${nombre_archivo}.tar.gz"

# Comprimir archivos, excluyendo .git, .rar y .gz
tar --exclude='*.git' --exclude='*.rar' --exclude='*.gz' -czvf "$archivo_comprimido"

# Agregar archivos al repositorio Git
git add "$archivo_comprimido"

# Realizar commit
git commit -m "Agregado archivo comprimido $archivo_comprimido"

# Hacer push
git push

echo "Proceso completado. Archivo comprimido: $archivo_comprimido, agregado al repositorio Git y se ha realizado el commit y push."
