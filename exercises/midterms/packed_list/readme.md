---
parent: გამოცდის საკითხების მაგალითები
---

# Packed List (70 ქულა)
typedef struct {<br/>
&nbsp;&nbsp;void&ast; base;<br/>
&nbsp;&nbsp;size_t alloc_bytes;<br/>
&nbsp;&nbsp;size_t bytes_used;<br/>
&nbsp;&nbsp;int num_elems;<br/>
&nbsp;&nbsp;size_t&ast; elem_offsets;<br/>
&nbsp;&nbsp;Free free_fn;<br/>
} PackedList;<br/>
<br/>
void PackedListInit(PackedList&ast; list, Free free_fn);<br/>
void PackedListDispose(PackedList&ast; list);<br/>
const void&ast; PackedListGet(const PackedList&ast; list, int index);<br/>
void PackedListAppend(PackedList&ast; list, void&ast; elem, size_t elem_size);<br/>
typedef int(&ast;CompareFn)(const void&ast;, const void&ast;);<br/>
void PackedListSort(PackedList&ast; list, CompareFn cmp);<br/>
<br/>
თქვენი ამოცანაა იმპლემენტაცია გაუკეთოთ ზემოთ აღწერილ ჯენერიკ PackedList სტრუქტურას, რომელიც საშუალებას მოგვცემს სხვადასხვა ზომის ინფორმაციები შევინახოთ მასში. სტრუქტურა არის ჰეტეროგენული, მასში ერთდროულად შეიძლება ინახებოდეს სხვადასხვა ტიპის მონაცემები, მაგალითად მთელი რიცხვი, ნამდვილი რიცხვი, სტრინგი ან სხვა ნებიმიერი ტიპის ცვლადი.<br/>
<br/>
მასში ელემენტების დამატება ხდება PackedListAppend ფუნქციის გამოძახებით, რომელსაც მონაცემზე მიმთითებელთან ერთად გადაეცემა თვითონ ამ მონაცემის ზომა ბაიტებში.<br/>
PackedList.base უნდა გამოიყენოთ სიაში დამატებული ელემენტების მიმდევრობით შესანახად, ხოლო PackedList.elem_offsets იმის დასამახსოვრებლად თუ რომელი ელემენტი PackedList.base მიმთითებლიდან რამდენ ბაიტში იწყება.<br/>
PackedListGet უნდა აბრუნებდეს გადაცემული ინდექსის მქონდე ელემენტის დასაწყის მისამართს მეხსიერებაში.<br/>
PackedListSort უნდა ასორტირებდეს სიაში შენახულ ელემენტებს გადაცემული შემადარებელი ფუნქციის გამოყენებით.<br/>
PackedListInit გამოიყენება სიის ინიციალიზაციისთვის, ხოლო PackedListDispose მის მიერ გამოყენებული მეხსიერების გასათავისუფლებლად. ყურადღება მიაქციეთ PackedListInit ფუნქციაზე გადაცემული free_fn დამხმარე ფუნქციას რომელიც სიის გათავისუფლებისას მასში შენახული ყოველი ელემენტის მისამართისთვის უნდა გამოიძახებოდეს.<br/>
<br/>
მაგალითად:<br/>
PackedList list;<br/>
PackedListInit(&list, /&ast;free_fn=&ast;/NULL);<br/>
PackedListAppend(&list, 2, sizeof(int));<br/>
PackedListAppend(&list, 5.7, sizeof(double));<br/>
PackedListAppend(&list, "foo", 4 &ast; sizeof(char));<br/>
ზემოთ აღწერილი კლიენტის კოდის შესრულების შემდეგ list.base უნდა უთითებდეს მინიმუმ 16 ბაიტიანი მეხსიერების სეგმენტის დასაწყისზე სადაც პირველ ოთხ ბაიტში შეინახება მთელი რიცხვი 2, შემდეგ რვა ბაიტში ნამდვილი რიცხვი 5.6 ხოლო მომდევნო ოთხ ბაიტში ნულით დასრულებული "foo" სტრიქონი. ანუ:<br/>
&ast;(int&ast;)PackedListGet(&list, 0) == 2<br/>
&ast;(double&ast;)PackedListGet(&list, 1) == 5.7<br/>
strcmp((char&ast;)PackedListGet(&list, 2), "foo") == 0<br/>
# IPList
typedef enum {<br/>
&nbsp;&nbsp;V4 = 0,<br/>
&nbsp;&nbsp;V6 = 1<br/>
} IPVersion;<br/>
<br/>
typedef struct {<br/>
&nbsp;&nbsp;IPVersion version;<br/>
&nbsp;&nbsp;char address[4];<br/>
} IPv4;<br/>
<br/>
typedef struct {<br/>
&nbsp;&nbsp;IPVersion version;<br/>
&nbsp;&nbsp;char* address;<br/>
} IPv6;<br/>
<br/>
void IPv4Init(IPv4* ip, char a, char b, char c, char d);<br/>
void IPv6Init(IPv6* ip, const char* address);<br/>
void IPv6Dispose(IPv6* ip);<br/>
<br/>
typedef PackedList IPList;<br/>
<br/>
void IPListInit(IPList* list);<br/>
void IPListDispose(IPList* list);<br/>
void IPListAppendV4(IPList* list, IPv4* v4);<br/>
void IPListAppendV6(IPList* list, IPv6* v6);<br/>
const void* IPListGet(IPList* list, int index);<br/>
void IPListSort(IPList* list);<br/>
<br/>
PackedList სტრუქტურის გამოყენებით ასევე იმპლემეტაცია უნდა გაუკეთოთ IPList სტრუქტურას რომელიც საშუალებას მოგვცემს სიაში შევინახოთ IPv4 და IPv6 მონაცემები. IP მისამართის მეოთხე ვერსიის დეფინიცია შედგება ოთხი მთელი რიცხვისაგან თითოეული 0 .. 255 შუალედიდან, ხოლო მეექვსე ვერსიის მისამართი კი არის სტრინგი.<br/>
IPListSort ფუნქციის იპლემენტაციისას გაითვალისწინეთ რომ მეოთხე ვერსიის IP მისამართები ითვლება უფრო ნაკლებად ვიდრე მეექვსე ვერსიის.<br/>
### ტესტები
სამაგალითო ტესტები იხილეთ packed_list/tests/tests.c ფაილში.<br/>
თქვენი ბიბლიოთეკების დასაკომპილირებლად და ტესტების გასაშვებათ გამოიყენეთ packed_list/run_tests.sh ან packed_list/run_tests.bat ფაილი იმის მიხედვით თუ რომელ ოპერაციულ სისტემას იყენებთ.
### შეფასების მექანიზმი
დავალების პირველი ნაწილის PackedList-ის იმპლემენტაციისთვის გამოყოფილია მთლიანი დავალების ქულების 60%, ხოლო IPList-ისთვის დანარჩენი 40%. ყოველ გატარებულ ტესტზე მეხსიერების არასწორად გამოყენების შემთხვევაში ტესტისთვის გამოყოფილი ქულის 15%-ს დაკარგავთ.<br/>
**გაითვალისწინეთ რომ header ფაილების შეცვლის უფლება არ გაქვთ.**
