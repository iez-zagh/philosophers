import random
import subprocess

def generate_random_numbers(n, lower_limit, upper_limit):
	numbers_set = set()
	while len(numbers_set) < n:
		numbers_set.add(random.randint(lower_limit, upper_limit))
	return list(numbers_set)

if __name__ == "__main__":
    n = 100
    lower_limit = -8559
    upper_limit = 8448

    for i in range(1000):  # Run push_swap 100 times
        random_numbers = generate_random_numbers(n, lower_limit, upper_limit)
        numbers_str = " ".join(map(str, random_numbers))
        command = f"./push_swap {numbers_str} | wc -l"
        result = subprocess.run(command, shell=True, capture_output=True, text=True)
        instructions_count = int(result.stdout.strip())
        print(f"Case {i+1}: {instructions_count} instructions")
        if instructions_count >= 700:
            print("Numbers:", numbers_str)
            break
