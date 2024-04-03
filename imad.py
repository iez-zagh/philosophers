import random
import subprocess

def generate_random_numbers(n, lower_limit, upper_limit):
    """Generate n random integers within the specified range."""
    random_numbers = [random.randint(lower_limit, upper_limit) for _ in range(n)]
    return random_numbers

if __name__ == "__main__":
    n = 100
    lower_limit = -8559
    upper_limit = 8448

    for _ in range(100):  # Run push_swap 100 times
        random_numbers = generate_random_numbers(n, lower_limit, upper_limit)
        numbers_str = " ".join(map(str, random_numbers))
        command = f"./push_swap {numbers_str}"
        subprocess.run(command, shell=True)
