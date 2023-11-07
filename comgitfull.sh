

# Obtener la fecha y hora actual en un formato deseado (por ejemplo, YYYYMMDD_HHMMSS)
fecha_hora_actual=$(date +'%Y%m%d_%H%M%S')

# Solicitar el nombre del archivo al usuario
read -p "Ingrese el nombre del archivo: " nombre_archivo

# Directorio donde se guardará el archivo comprimido
ruta_destino="../"

archivo_comprimido="${ruta_destino}/${nombre_archivo}_${fecha_hora_actual}.tar.gz"

# Agregar archivos al repositorio Git

git add .
git commit -m "${nombre_archivo}"
git push

# Comprimir archivos, excluyendo .git, .rar y .gz
tar --directory="${ruta_destino}" --exclude='*.git' --exclude='*.rar' --exclude='*.gz' -czvf "${archivo_comprimido}" *

echo "Proceso completado. Archivo comprimido y se ha realizado el commit y push en la ruta ${ruta_destino}."
