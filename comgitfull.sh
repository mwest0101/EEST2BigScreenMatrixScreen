#!/bin/bash
# Solicitar el nombre del archivo al usuario
read -p "Ingrese el nombre del archivo: " nombre_archivo
archivo_comprimido="${nombre_archivo}.tar.gz"



# Agregar archivos al repositorio Git
git add .
git commit -m "${nombre_archivo}"
git push



# Comprimir archivos, excluyendo .git, .rar y .gz
tar --exclude='*.git' --exclude='*.rar' --exclude='*.gz' --exclude='*.zip' -czvf "$archivo_comprimido" *

echo "Proceso completado. Archivo comprimido y se ha realizado el commit y push."
