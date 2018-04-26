import subprocess
from time import sleep
def main():
    count = 0
    while True:
        result = subprocess.getoutput('./a.out')
        count += 1
        if(result[-1] is 'I'):
            print(count)
            exit()
        sleep(1)


if __name__ == '__main__':
    main()