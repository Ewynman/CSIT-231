#!/bin/sh

#removed the old version of fibonacci.out
rm fibonacci.out

#Makes now a variable for the date
now=$(date)
echo "Start: $now" | tee -a fibonacci.out

#Prints the start time and date
starttime=$(date +%s%N) | tee -a fibonacci.out

#Shows the number the number the user wants
echo -e "Number: $1 "| tee -a fibonacci.out

#If userinput is <= 1 say theres an error and ends to program
if [ "$1" -le  1 ]; then
    echo "The number cannot less than 1"
    exit 1
fi

#lets user choose if they want it done recursivly or not by case staement
echo -e "Enter Your Choice of How you want things done(R, r, N, n): "
read userchoice

case $userchoice in
    
    R)
        echo -e "Recursive"
    ;;
    
    r)
        echo -e "Recursive"
    ;;
    
    N)
        echo -e "Non-Recursive"
    ;;
    
    n)
        echo -e "Non-Recursive"
    ;;
    *) echo -e "You Must enter R,r,N,n"
esac

echo -e "The Calculations have Begun"

#if the user chooses R or r rrun the recursive fib fdunction
if [[ "$userchoice" = "R" || "$userchoice" = "r" ]]; then
    function fibonacci
    {
        x=1
        y=2
        i=3
        echo "fibonaccionacci Series up to $1 terms :" | tee -a fibonacci.out
        echo "Run     fibonaccionacci     time" | tee -a fibonacci.out
        echo "$x" | tee -a fibonacci.out
        echo "$y" | tee -a fibonacci.out
        while [ $i -lt $1 ]
        do
            calcstarttime=$(date +%s%N)
            i=`expr $i + 1 `
            z=`expr $x + $y `
            calcendtime=$(date +%s%N)
            totalcalc=$(($calcendtime-$calcstarttime))
            echo "$i        $z              $totalcalc" | tee -a fibonacci.out
            x=$y
            y=$z
        done
    }
fi
r=`fibonacci $1`
echo -e "$r"

#if user chooses N or n run the nofibn function 
if [[ "$userchoice" = "N" || "$userchoice" = "n" ]]; then
    function nofibonacci
    {
        xx=0
        yy=1
        z=0
        echo -e "fibonaccionacci Series up to $1 terms Non Recursive" | tee -a fibonacci.out
        echo -e "Run     fibonaccionacci      Time" | tee -a fibonacci.out
        if [[ $1 < 1 ]]; then
            echo "$1" | tee -a fibonacci.out
        fi
        for((i = 0 ; i < $1 -1 ; i++));
        do
            noncalcstarttime=$(date +%s%N)
            z=`expr $xx + $yy`
            noncalcendtime=$(date +%s%N)
            nontotalcalc=$(($noncalcendtime-$noncalcstarttime))
            echo "$i       $z               $nontotalcalc" | tee -a fibonacci.out
            xx=$yy
            yy=$z
        done
    }
fi
r=`nofibonacci $1`
echo "$r"

#ends the time
endtime=$(date +%s%N)

#prints the final date and time
echo -e "$now" | tee -a fibonacci.out

#calculaste the total time
totaltime=$(($endtime-$starttime))

#calculate the average time
avgtime=`expr $totaltime / $1`


#print out average time and the total time in nanoseconds
echo -e "Average  Time: $avgtime in nanoseconds" | tee -a fibonacci.out
echo -e "The Run Has Finished" | tee -a fibonacci.out
echo -e "Overall Elapsed time: $totaltime in nanoseconds" | tee -a fibonacci.out