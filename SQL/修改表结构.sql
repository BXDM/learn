use mytime;
delete from list where num = '2019-03-19';#删除表记录
delete from list where num = '2019-03-29';
#alter table list modify date date;	# 更改表的数据类型
#alter table list add start time after date;		#在date 字段后插入新字段
#alter table list add end time after start;