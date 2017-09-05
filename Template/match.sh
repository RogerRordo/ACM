g++ $2 -o 1.out
g++ $3 -o 2.out
cnt=0;
while true; do
g++ $1 -o dm.out
./dm.out>dm.txt
./1.out<dm.txt>1.txt
./2.out<dm.txt>2.txt
if diff 1.txt 2.txt; then let "cnt+=1"; echo ${cnt};
else exit 0;
fi
done
