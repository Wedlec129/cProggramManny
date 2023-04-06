#!/usr/bin/python
import fuse
import stat
import errno

fuse.fuse_python_api=(0,2)

class default_stat(fuse.Stat):
    def __init__(self):
        self.st_mode = 0
        self.st_ino = 0
        self.st_dev = 0
        self.st_nlink = 0
        self.st_uid = 0
        self.st_gid = 0
        self.st_size = 0
        self.st_atime = 0
        self.st_mtime = 0 
        self.st_ctime = 0

class simple_fuse(fuse.Fuse):
        #возращает атрибуты обектат/ директории/ файлы
        def getaddr(self,path): 
            if path in ['/','.','..','/1.txt']:
                return -errno.ENOENT

            st = default_stat()
              
            if path in['/','.','..']:
                st.st_mode = stat.S_IFDIR | 0o755
                st.st_nlink = 2
            else:
                st.st_mode = stat.S_IFREG | 0o755
                st.st_nlink = 1
                st.st_size=len(b"hello world\n")
            return st

        def open(self, path, flags):
            pass

            #типо если попробуем прочитать файл
        def read(self, path, size, offset):
            print(path)
            return b"hello world\n"


        def readdir(self, path, size, offset):
            print(path)
            for d in ['.','..','1.txt']: #. - это мнимоника тек деректори, .. это мним род дер , и тот файл
                yield fuse.Direntry(d)


        

if __name__ == '__main__':
    driver = simple_fuse(
        version = "%prog " + fuse.__version__,
        usage=fuse.Fuse.fusage,dash_s_do="setsingle"
    )
    driver.parse(errex=1)
    driver.main()
   