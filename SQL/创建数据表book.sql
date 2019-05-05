/*use mytime;
create table book
(
    ids int auto_increment primary key,
    name text,
    author varchar(20),
    borrow date,
    returnt date
);
set @t = date_add(current_date(),interval '28' day);
insert into book values(null,'《数值计算方法的计算机实现》','徐士良',current_date(),@t);
*/

use mytime;
alter table book change ids items int auto_increment;
