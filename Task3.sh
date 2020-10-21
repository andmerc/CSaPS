inputfilename=$1
outputfilename=$2
if [ -z $inputfilename ]; then
	echo 'Наименование входного файла отсутствует'
else
	if [ -z $outputfilename ]; then
		echo 'Наименование выходного файла отсутствует'
	else 
		for word in $(cat $inputfilename); do
			echo "${word,,}"
		done > $outputfilename;
		echo 'Текст файла '$inputfilename' записан в файл '$outputfilename' в нижнем регистре'
	fi
fi