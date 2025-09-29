# test basic range with numbers 0–15
echo "3 -4 5 1 7 0 8 0 15 12 3 5 3 3 3 3 3" | ./histo

# test number just outside initial range
echo "18" | ./histo

# test much larger number
echo "150" | ./histo

# test mixed numbers with scaling
echo "1 2 3 50 100 200" | ./histo
