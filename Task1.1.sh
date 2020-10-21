files=(*.*)
if [ ${#files[*]} -gt 0 ]; then
	echo "В данной папке есть хотя бы один файл"
else
	echo "В данной папке нет файлов"
fi