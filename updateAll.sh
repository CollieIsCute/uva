#!bash
file="README.md"

#auto clang-format
clang-format -style=file -i */*.[ch]* 

#write Readme
function printLevel {
	local level=`cat questionLevel | fgrep -w $1 | cut -f 2`
	printf " " >> $file
	for i in $(seq 5)
	do
		if [ $i -le $level ]; then
			echo -n "★" >> $file
		else
			echo -n "☆" >> $file
		fi
	done
	echo -n " |" >> $file
}

#update Readmetext
temp=`cat $file| fgrep -on "### 完成的" | cut -f 1 -d ':' `
head -n $temp $file > new_README.md
rm $file
mv new_README.md $file
#update ReadmeTable
echo -e "- 共<b> "`ls | sort -n | grep '[0-9]' | wc -w`" </b>題\n" >> $file
echo '| 題號 | 星數 | source code | screenshot | makefile | solution.txt |' >> $file
echo '| :--------: | :--------: | :--------: | :--------: | :--------: | :--------: |' >> $file
lack=()
for problemNum in $(ls | sort -n | grep '[0-9]')
do
	echo -n "| <b>$problemNum</b> |" >> $file
	printLevel $problemNum
	if [ -e $problemNum\/$problemNum.* ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' <b>X</b> |' >> $file
		lack+=("$problemNum source code")
	fi
	if [ -e $problemNum\/*Screenshot* ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' <b>X</b> |' >> $file
		lack+=("$problemNum screenshot")
	fi
	if [ -e $problemNum\/[Mm]akefile ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' <b>X</b> |' >> $file
		lack+=("$problemNum makefile")
	fi
	if [ -e $problemNum\/[sS]olution.txt ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' <b>X</b> |' >> $file
		lack+=("$problemNum solution.txt")
	fi
	echo >>$file
done

# print out which file needed to terminal
for line in "${lack[@]}"
do
	echo updateAll: need $line
done