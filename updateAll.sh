#!bash
file="README.md"

#auto clang-format
clang-format -i */*.[ch]*

#write Readme
function printLevel {
	local level=`cat questionLevel | fgrep -w $1 | cut -f 2`
	printf " " >> $file
	for i in $(seq 5)
	do
		if [ "$i" -le "$level" ]; then
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
echo -e "- 共"`ls | sort | grep '[0-9]' | wc -w`"題\n" >> $file
echo '| 題號 | 星數 | source code | screenshot | makefile | solution.txt |' >> $file
echo '| :--------: | :--------: | :--------: | :--------: | :--------: | :--------: |' >> $file
for problemNum in $(ls | sort | grep '[0-9]')
do
	echo -n "| $problemNum |" >> $file
	printLevel $problemNum
	if [ -e $problemNum\/$problemNum.* ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' X |' >> $file
	fi
	if [ -e $problemNum\/*Screenshot* ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' X |' >> $file
	fi
	if [ -e $problemNum\/[Mm]akefile ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' X |' >> $file
	fi
	if [ -e $problemNum\/[sS]olution.txt ]; then
		echo -n ' O |' >> $file
	else
		echo -n ' X |' >> $file
	fi
	echo >>$file
done