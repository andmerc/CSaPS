filename=$1
if [ -z $filename ]; then
	echo 'Наименование файла отсутствует'
else
	echo 'Размер файла '$filename': '$(stat --format=%s $filename)
fi
