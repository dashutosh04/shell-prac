# Write a shell program to print Prime number between 1 - 100 #

echo "Enter a number between 1 - 100 to check if its prime. "
read number

case $number in
    2|3|5|7|11|13|17|19|23|29|31|37|41|43|47|53|59|61|67|71|73|79|83|89|97)
        echo "$number is a prime number."
        ;;
    *)
        echo "$number is not a prime number."
        ;;
esac