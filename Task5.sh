array=(1 2 3 4 5 6 7 8 9 10)
sum=0
(partsum=0
for index in {0..4}; do
	let "partsum = partsum + ${array[index]}"
done
echo $partsum) | (read sum;
for index in {5..9}; do
	let "sum = sum + ${array[index]}"
done
echo 'Сумма эдементов массива: '$sum)