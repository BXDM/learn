use mytime;
set @t = now();
insert into list values(null,date(@t),time(@t),null,null,'学习SQL');