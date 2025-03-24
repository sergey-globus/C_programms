#cd ..
for file in func_tests/data/pos_*_args.txt; do
	echo "Start processing - `basename $file | sed 's/_args\.txt//'`"
	valgrind -q ./app.exe `cat $file`
	diff -w "$(echo $file | sed 's|_args|_out|')" "out/out.txt" && echo "passed" || echo "failed"
	
	echo "Code exit - $?\n"
done
for file in func_tests/data/neg_*_args.txt; do
	echo "Start processing - `basename $file | sed 's/_args\.txt//'`"
	valgrind -q ./app.exe `cat $file`
	echo "Code exit - $?"
done
