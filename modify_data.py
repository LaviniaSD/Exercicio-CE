# No need to run again!
def increase_size(path):
    with open(path, 'r+b') as f:
        f.seek(0)
        content = f.read()
        for i in range(200):
            f.write(content)

if __name__ == '__main__':
    increase_size('shakespeare.txt')