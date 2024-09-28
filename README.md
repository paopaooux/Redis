# 基于C++17  实现的简易Redis



## Build

```
mkdir -p build && cd build && cmake .. && make
```

## Use

服务端`./build/src/main/server`

客户端 `./build/src/client`  后接命令:

```
# hashtable
set key value 
get key 
keys 									#返回哈希表的所有元素
# zset
zadd   zset_name value key
zrem   zset_name value key         		# 删除
zscore zset_name key               		# 查询值
zquery zset_name value key offset limit #返回从键值对偏移offset开始的limit个元素
# TTL
pexpire key TTL  						# 设置键存活时间,单位为毫秒
pttl key      							# 查看存活时间
```

 键值表里的元素为哈希表的key和zset名，所以Redis支持使用一个哈希表和多个zset，哈希表元素和zset删除用pexpire，zset内的t元素的删除用zrem



## Test

确保先build

```
python3 test/redis_test.py
```

## Reference

[Build Your Own Redis with C/C++](https://build-your-own.org/redis/)

## Other

C 版本Redis实现 [my_redis](https://github.com/paopaooux/my-redis)