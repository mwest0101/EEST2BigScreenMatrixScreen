#!/bin/bash
# Solicitar el nombre del archivo al usuario
read -p "Ingrese el nombre del archivo: " nombre_archivo

fecha=$(date +"%Y%m%d%H%M%S")


ruta_destino="./Backups"
archivo_comprimido="${fecha}_${nombre_archivo}.tar.gz"

echo "Archivo a comprimir $archivo_comprimido"

echo "____ ____ ___ _  _ ____ _    _ ___  ____ _  _ ___  ____    ____ _ ___"
echo "|__| |     |  |  | |__| |    |   /  |__| |\ | |  \ |  |    | __ |  | "
echo "|  | |___  |  |__| |  | |___ |  /__ |  | | \| |__/ |__|    |__] |  | "
echo ""



# Agregar archivos al repositorio Git
git add .
git commit -m "$fecha: ${nombre_archivo}"
git push

echo "____ ____ _  _ ___  ____ _ _  _ _ ____ _  _ ___  ____"
echo "|    |  | |\/| |__] |__/ | |\/| | |___ |\ | |  \ |  |"
echo "|___ |__| |  | |    |  \ | |  | | |___ | \| |__/ |__|"
echo ""




# Comprimir archivos, excluyendo .git, .rar y .gz
tar --directory="${ruta_destino}" --exclude='*.git' --exclude='*.rar' --exclude='*.gz' --exclude='*.zip' -czvf "$archivo_comprimido" *

echo "Proceso completado. Archivo comprimido y se ha realizado el commit y push."
