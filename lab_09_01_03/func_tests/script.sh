#cd ..
for file in func_tests/data/pos_*_args.txt; do
	echo "Start processing - `basename $file | sed 's/_args\.txt//'`"
	valgrind -q --leak-check=full ./app.exe `cat $file`
	echo "Code exit - $?"
done
for file in func_tests/data/neg_*_args.txt; do
	echo "Start processing - `basename $file | sed 's/_args\.txt//'`"
	valgrind -q --leak-check=full ./app.exe `cat $file`
	echo "Code exit - $?"
done
