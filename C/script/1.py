import subprocess
from time import sleep


def main():
    result = [] #平均値を格納するリスト
    for i in range(0, 100):  # 100回ループ
        output = subprocess.getoutput('./a.out')  # プログラム実行
        result.append(output[-1])  # 実行プログラムの出力の一番最後の文字が平均値である
        sleep(1)  # seed値に時間を使っているので1秒待つ

    for i in range(0, 6):
        count = result.count(str(i + 1))
        print('{}: {}回'.format(i + 1, count))


if __name__ == '__main__':
    main()
