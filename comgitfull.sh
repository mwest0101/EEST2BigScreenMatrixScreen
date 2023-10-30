#!/bin/bash
# Solicitar el nombre del archivo al usuario
read -p "Ingrese el nombre del archivo: " nombre_archivo


# Agregar archivos al repositorio Git
git add .
git commit -m "Agregado archivo comprimido $archivo_comprimido"
git push

archivo_comprimido="${nombre_archivo}.tar.gz"

# Comprimir archivos, excluyendo .git, .rar y .gz
tar --exclude='*.git' --exclude='*.rar' --exclude='*.gz' -czvf "$archivo_comprimido"

echo "Proceso completado. Archivo comprimido y se ha realizado el commit y push."
