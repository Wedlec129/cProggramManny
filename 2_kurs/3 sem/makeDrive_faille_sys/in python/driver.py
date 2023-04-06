#!/usr/bin/python3

import fuse
from fuse import Fuse
import stat, errno
import json
import os
import requests

fuse.fuse_python_api = (0, 2)

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

class simple_fuse(Fuse):
    def getentry(self,path):
        chain = path.strip('/').split('/')
        r = requests.get(self.tree + path).json()
        print(r)
        return r

    def main(self,tree_name):
        self.tree = tree_name
        super().main()
        
    def getattr(self, path):
        if path in ['.','..'] :
            st = default_stat()
            st.st_mode = stat.S_IFDIR | 0o755
            st.st_nlink = 2
            return st
        
        entry = self.getentry(path)
        if not entry: return -errno.ENOENT
        st = default_stat()
        if "list" in entry:
            st.st_mode = stat.S_IFDIR | 0o755
            st.st_nlink = 2
        else:
            st.st_mode = stat.S_IFREG | 0o755
            st.st_nlink = 1
            st.st_size = 0 if 'data' not in entry else len(entry['data'].encode("UTF-8"))
        return st
    def open(self, path, flags):
        if not self.getentry(path):
            return -errno.ENOENT
    
    def read(self, path, size, offset):
        entry = self.getentry(path)
        if (not entry) or ("data" not in entry):
            return -errno.ENOENT
        data = '' if 'data' not in entry else entry['data']
        return data.encode('utf-8')
    
    def readdir(self, path, offset):
        entry = self.getentry(path)
        if (not entry) or ('list' not in entry):
            return -errno.ENOENT
        for d in entry['list']:
            yield fuse.Direntry(d)
        
if __name__ == '__main__':
    driver = simple_fuse(
        version = "%prog " + fuse.__version__,
        usage=Fuse.fusage,dash_s_do="setsingle"
    )
    driver.parse(errex=1)
    driver.main("http://127.0.0.1:8000")