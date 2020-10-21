for (( n=1; n <= 5; n++ ))
do
	mkdir $n
	cd $n
	touch $n
	echo $n >> $n
	cd ..
done