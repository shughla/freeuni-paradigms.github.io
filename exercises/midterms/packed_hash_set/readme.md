# Packed HashSet (70 ქულა)
typedef void(*Free)(void*);<br/>
typedef int(*UniqueHash)(const void*);<br/>
<br/>
typedef struct {<br/>
&nbsp;&nbsp;void* base;<br/>
&nbsp;&nbsp;size_t alloc_bytes;<br/>
&nbsp;&nbsp;size_t bytes_used;<br/>
&nbsp;&nbsp;int num_elems;<br/>
&nbsp;&nbsp;size_t* elem_offsets;<br/>
&nbsp;&nbsp;int* elem_hashes;<br/>
&nbsp;&nbsp;UniqueHash hash_fn;<br/>
&nbsp;&nbsp;Free free_fn;<br/>
} PackedHashSet;<br/>
<br/>
void PackedHashSetInit(PackedHashSet* set, UniqueHash hash_fn, Free free_fn);<br/>
void PackedHashSetDispose(PackedHashSet* set);<br/>
const void* PackedHashSetFind(PackedHashSet* set, const void* elem);<br/>
const void* PackedHashSetGet(PackedHashSet* set, int index);<br/>
bool PackedHashSetInsert(PackedHashSet* set, void* elem,<br/>
			 size_t elem_size);<br/>
void PackedHashSetSortByHash(PackedHashSet* set);<br/>
<br/>
თქვენი ამოცანაა იმპლემენტაცია გაუკეთოთ ზემოთ აღწერილ ჯენერიკ PackedHashSet სტრუქტურას, რომელიც საშუალებას მოგვცემს სხვადასხვა ზომის ინფორმაციები შევინახოთ მასში. სტრუქტურა არის ჰეტეროგენული, მასში ერთდროულად შეიძლება ინახებოდეს სხვადასხვა ტიპის მონაცემები, მაგალითად მთელი რიცხვი, ნამდვილი რიცხვი, სტრინგი ან სხვა ნებიმიერი ტიპის ცვლადი.<br/>
ერთადერთი მოთხოვნა რაც PackedHashSet სტრუქტურას გააჩნია არის რომ მისთვის გადაცემული ჰეშირების ფუნქცია განსხვავებულ ინფორმაციებზე განსხვავებულ ჰეშ მნიშვნელობებს ანბრუნებდეს. ანუ ის თვლის რომ თუ ორი მონაცემის ჰეშ მნიშვნელობები ემთხვევა მაშინ ეს მონაცემები ერთმანეთის ტოლია.
<br/>
მასში ელემენტების დამატება ხდება PackedHashSetInsert ფუნქციის გამოძახებით, რომელსაც მონაცემზე მიმთითებელთან ერთად გადაეცემა თვითონ ამ მონაცემის ზომა ბაიტებში. თუ ინფორმაცია იგივე ჰეშ მნიშვნელობით უკვე არსებობს სიმრავლეში მაშინ PackedHashSetInsert ფუნქციამ უნდა დააბრუნოს false, წინააღმდეგ შემთხვევაში ახალი ელემენტი უნდა დაამატოს სიაში და დააბრუნოს true.<br/>
PackedHashSet.base უნდა გამოიყენოთ სიმრავლეში დამატებული ელემენტების მიმდევრობით შესანახად, ხოლო PackedHashSet.elem_offsets იმის დასამახსოვრებლად თუ რომელი ელემენტი PackedHashSet.base მიმთითებლიდან რამდენ ბაიტში იწყება. PackedHashSet.elem_hashes შეგიძლიათ გამოიყუნოთ სიმრავლეში დამატებული ელემენტების ჰეშ მნიშვნელობების შესანახად.<br/>
PackedHashSetGet უნდა აბრუნებდეს გადაცემული ინდექსის მქონდე ელემენტის დასაწყის მისამართს მეხსიერებაში.<br/>
PackedHashSetFind უნდა აბრუნდებდეს გადაცემული ელემენტის მისამართს მეხსიერებაში თუ იგი მოიძებნა სიმრავლეში და NULL-ს წინააღმდეგ შემთხვევაში.<br/>
PackedHashSetSortByHash უნდა ასორტირებდეს სიმრავლეში შენახულ ელემენტებს მათ ჰეშირებული მნიშვნელობების ზრდადობის მიხედვით.<br/>
PackedHashSetInit გამოიყენება სიმრავლის ინიციალიზაციისთვის, ხოლო PackedHashSetDispose მის მიერ გამოყენებული მეხსიერების გასათავისუფლებლად. ყურადღება მიაქციეთ PackedHashSetInit ფუნქციაზე გადაცემული free_fn დამხმარე ფუნქციას რომელიც სიმრავლის გათავისუფლებისას მასში შენახული ყოველი ელემენტის მისამართისთვის უნდა გამოიძახებოდეს.<br/>
<br/>
მაგალითად:<br/>
int IntHash(void* pt) {<br/>
&nbsp;&nbsp;return *(int*);<br/>
}<br/>
<br/>
PackedHashSet ints;<br/>
PackedHashSetInit(&ints, IntHash, /&ast;free_fn=&ast;/NULL);<br/>
int two = 2, five = 5;<br/>
PackedHashSetInsert(&ints, &two, sizeof(int));<br/>
PackedHashSetInsert(&list, &five, sizeof(int));<br/>
ზემოთ აღწერილი კლიენტის კოდის შესრულების შემდეგ ints.base უნდა უთითებდეს მინიმუმ 8 ბაიტიანი მეხსიერების სეგმენტის დასაწყისზე სადაც პირველ ოთხ ბაიტში შეინახება მთელი რიცხვი 2 ხოლო შემდეგ ოთხ ბაიტში მთელი რიცხვი 5.<br/>
&ast;(int&ast;)PackedHashSetGet(&list, 0) == 2<br/>
&ast;(int&ast;)PackedHashSetGet(&list, 1) == 5<br/>
# TupleHashSet
typedef enum {<br/>
&nbsp;&nbsp;CHAR_PAIR = 0,<br/>
&nbsp;&nbsp;CHAR_TRIPLE = 1<br/>
} TupleType;<br/>
<br/>
typedef struct {<br/>
&nbsp;&nbsp;TupleType tuple_type;<br/>
&nbsp;&nbsp;char first;<br/>
&nbsp;&nbsp;char second;<br/>
} CharPair;<br/>
<br/>
typedef struct {<br/>
&nbsp;&nbsp;TupleType tuple_type;<br/>
&nbsp;&nbsp;char first;<br/>
&nbsp;&nbsp;char second;<br/>
&nbsp;&nbsp;char third;<br/>
} CharTriple;<br/>
<br/>
void CharPairInit(CharPair* pair, char first, char second);<br/>
void CharTripleInit(CharTriple* triple, char first, char second, char third);<br/>
<br/>
typedef PackedHashSet TupleHashSet;<br/>
<br/>
void TupleHashSetInit(TupleHashSet* set);<br/>
void TupleHashSetDispose(TupleHashSet* set);<br/>
bool TupleHashSetInsertCharPair(TupleHashSet* set, CharPair* pair);<br/>
bool TupleHashSetInsertCharTriple(TupleHashSet* set, CharTriple* triple);<br/>
const void* TupleHashSetGet(TupleHashSet* set, int index);<br/>
const void* TupleHashSetFind(TupleHashSet* set, const void* elem);<br/>
void TupleHashSetSort(TupleHashSet* set);<br/>
<br/>
PackedHashSet სტრუქტურის გამოყენებით ასევე იმპლემეტაცია უნდა გაუკეთოთ TupleHashSet სტრუქტურას რომელიც საშუალებას მოგვცემს სიმრავლეში შევინახოთ ზემოთ აღწერილი CharPair და CharTripple ტიპების მონაცემები. სადაც CharPair საშუალებას გვაძლევს ორი ერთ ბაიტიანი მონაცემიიის ხოლო CharTripple სამი ერთბაიტიანი ინფორმაციის შენახვას.<br/>
TupleHashSetSort ფუნქციის იპლემენტაციისას მოგიწევთ ისეთი ჰეშირების ფუნქციის მოფიქრება რომელიც გაითვალისწინეთ შემდეგ ლოგიკას: CharPair ტიპის მონაცემები ითვლაბა ნაკლებად ვიდრე CharTripple, ხოლო ერთი და იგივე ტიპის მონაცემები დარდება მასში შენახული ბაიტების მნიშვნელობების ზრდადობის მიხედვით. ანუ CharPair {1, 2} < CharTripple {1, 1, 1} და CharPair {5, 2} < CharPair {5, 3}.
### ტესტები
სამაგალითო ტესტები იხილეთ packed_hash_set/tests/tests.c ფაილში.<br/>
თქვენი ბიბლიოთეკების დასაკომპილირებლად და ტესტების გასაშვებათ გამოიყენეთ packed_hash_set/run_tests.sh ან packed_hash_set/run_tests.bat ფაილი იმის მიხედვით თუ რომელ ოპერაციულ სისტემას იყენებთ.
### შეფასების მექანიზმი
დავალების პირველი ნაწილის PackedHashSet-ის იმპლემენტაციისთვის გამოყოფილია მთლიანი დავალების ქულების 60%, ხოლო TupleHashSet-ისთვის დანარჩენი 40%. ყოველ გატარებულ ტესტზე მეხსიერების არასწორად გამოყენების შემთხვევაში ტესტისთვის გამოყოფილი ქულის 15%-ს დაკარგავთ.<br/>
**გაითვალისწინეთ რომ header ფაილების შეცვლის უფლება არ გაქვთ.**
