# KECERDASAN BUATAN - F

Muhammmad Daffa' Aflah Syarif - 05111840000030

Teknik Informatika - Fakultas Teknologi Elektro & Informatika Cerdas

Institut Teknologi Sepuluh Nopember Surabaya

# 1. 8 Queen - Hill Climbing
Source Code : [8queen-hill-climbing.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/8%20queen%20-%20hill%20climbing/n-queen.cpp)

Dalam program, bagian untuk mengecek apakah sebuah queen bisa diserang oleh queen lain bisa dilihat pada program dibawah ini.
```
int is_attack(int i,int j) {
    int k,l;
    //checking if there is a queen in row or column
    for(k=0;k<N;k++) {
        if((board[i][k] == 1) || (board[k][j] == 1))
            return 1;
    }
    //checking for diagonals
    for(k=0;k<N;k++) {
        for(l=0;l<N;l++) {
            if(((k+l) == (i+j)) || ((k-l) == (i-j))) {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}
```

Kemudian, setelah dirasa tidak ada queen yang menyerang, maka program dibawah ini merupakan bagian untuk meletakkan queen yang dirasa aman.
```
int N_queen(int n) {
    int i,j;
    //if n is 0, solution found
    if(n==0)
        return 1;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            //checking if we can place a queen here or not
            //queen will not be placed if the place is being attacked
            //or already occupied
            if((!is_attack(i,j)) && (board[i][j]!=1)) {
                board[i][j] = 1;
                //recursion wether we can put the next queen with this arrangment or not
                if(N_queen(n-1)==1) {
                    return 1;
                }
                board[i][j] = 0;
            }
        }
    }
    return 0;
}
```

Hill Climbing adalah pencarian heuristik yang digunakan untuk masalah optimasi matematis di bidang Inteligensi Buatan.

Dengan sejumlah besar input dan fungsi heuristik yang baik, ia mencoba untuk menemukan solusi yang cukup baik untuk masalah tersebut. Solusi ini mungkin bukan global optimal maksimum.
- Dalam definisi di atas, `Mathematical Optimization Problems` menyiratkan bahwa mendaki bukit memecahkan masalah di mana kita perlu memaksimalkan atau meminimalkan fungsi nyata yang diberikan dengan memilih nilai dari input yang diberikan. Contoh-Traveling salesman masalah di mana kita perlu meminimalkan jarak yang ditempuh oleh salesman.
- `Heuristic Search` berarti bahwa algoritma pencarian ini mungkin tidak menemukan solusi optimal untuk masalah tersebut. Namun, itu akan memberikan solusi yang baik dalam waktu yang wajar.
- `Heuristic Function` adalah fungsi yang akan memberi peringkat semua alternatif yang mungkin pada setiap langkah percabangan dalam algoritma pencarian berdasarkan informasi yang tersedia. Ini membantu algoritma untuk memilih rute terbaik dari rute yang mungkin.

![hc](https://user-images.githubusercontent.com/52326074/77150635-e36f1c00-6ac6-11ea-977e-153dd3b862e3.png)

## Fitur Hill Climbing
### a. Varian dari menghasilkan dan menguji algoritma

Ini adalah varian dari algoritma generate and test. Algoritma generate and test adalah sebagai berikut:
- Hasilkan solusi yang mungkin.
- Tes untuk melihat apakah ini solusi yang diharapkan.
- Jika solusinya telah ditemukan, keluar lagi, lanjutkan ke langkah 1.

Oleh karena itu kami menyebut Hill climbing sebagai varian dari algoritma hasil dan uji karena mengambil umpan balik dari prosedur pengujian. Kemudian umpan balik ini digunakan oleh generator dalam memutuskan langkah selanjutnya dalam ruang pencarian.

### b. Menggunakan Greedy Aproach

Pada titik mana pun di ruang keadaan, pencarian bergerak ke arah itu saja yang mengoptimalkan biaya fungsi dengan harapan menemukan solusi optimal di akhir.

## Jenis Hill Climbing
### a. Simple Hill Climbing

Ini memeriksa node tetangga satu per satu dan memilih node tetangga pertama yang mengoptimalkan biaya saat ini sebagai node berikutnya. Ini memeriksa node tetangga satu per satu dan memilih node tetangga pertama yang mengoptimalkan biaya saat ini sebagai node berikutnya.

Algoritma Simple Hill climbing :
- Evaluasi keadaan awal. Jika itu adalah keadaan tujuan maka berhentilah dan kembalikan kesuksesan. Kalau tidak, jadikan kondisi awal sebagai kondisi saat ini.
- Loop sampai keadaan solusi ditemukan atau tidak ada operator baru yang dapat diterapkan ke keadaan saat ini.
- Exit

### b. Steepest-Ascent Hill Climbing

Pertama-tama memeriksa semua node tetangga dan kemudian memilih simpul yang paling dekat dengan keadaan solusi pada simpul berikutnya.

- Evaluasi keadaan awal. Jika status tujuan maka keluar dari yang lain jadikan status saat ini sebagai keadaan awal
- Ulangi langkah ini sampai solusi ditemukan atau keadaan saat ini tidak berubah
- Exit

### c. Stochastic Hill Climbing

Itu tidak memeriksa semua node tetangga sebelum memutuskan node mana yang akan dipilih. Itu hanya memilih node tetangga secara acak dan memutuskan (berdasarkan jumlah peningkatan tetangga itu) apakah akan pindah ke tetangga itu atau untuk memeriksa yang lain.

## State Space Diagram untuk Hill Climbing

adalah representasi grafis dari himpunan status yang dapat dicapai oleh algoritma pencarian kami vs nilai fungsi objektif kami (fungsi yang ingin kami maksimalkan).

`X - axis` menunjukkan ruang keadaan yaitu keadaan atau konfigurasi yang dapat dicapai algoritma kami.

`Y - axis` menunjukkan nilai-nilai fungsi obyektif yang sesuai dengan keadaan tertentu.

Solusi terbaik adalah ruang negara di mana fungsi objektif memiliki nilai maksimum (global maksimum).

![8phc](https://user-images.githubusercontent.com/52326074/77142942-355a7680-6ab4-11ea-8c1d-66b86aaef6c9.png)

## Daerah berbeda di State Space Diagram

- `Local Maximum` Ini adalah state yang lebih baik daripada state tetangganya namun ada state yang lebih baik daripada itu (global maksimum). Keadaan ini lebih baik karena di sini nilai fungsi objektif lebih tinggi daripada tetangganya.
- `Global Maximum` Ini adalah keadaan terbaik yang mungkin dalam diagram ruang keadaan. Ini karena pada keadaan ini, fungsi objektif memiliki nilai tertinggi.
- `Plateua/Flat Local Maximum` Ini adalah wilayah datar ruang negara di mana negara-negara tetangga memiliki nilai yang sama.
- `Ridge` Ini adalah wilayah yang lebih tinggi dari tetangganya tetapi memiliki kemiringan. Ini adalah jenis khusus maksimum lokal.
- `Current State` Wilayah diagram ruang keadaan tempat kami saat ini hadir selama pencarian.
- `Shoulder` Ini adalah dataran tinggi yang memiliki tepi menanjak.

## Permasalahan di Berbagai Daerah di Hill Climbing

- `Local Maximum` semua state tetangga memiliki nilai yang lebih buruk daripada keadaan saat ini. Karena Hill Climbing menggunakan pendekatan serakah, itu tidak akan bergerak ke keadaan yang lebih buruk dan mengakhiri dirinya sendiri. Proses ini akan berakhir meskipun mungkin ada solusi yang lebih baik.  

`To Overcome Local Maximum Problem` Gunakan teknik backtracking. Menyimpan daftar negara yang dikunjungi. Jika pencarian mencapai kondisi yang tidak diinginkan, pencarian dapat mundur ke konfigurasi sebelumnya dan menjelajahi jalur baru.

- `Plateau` Di plateau semua tetangga memiliki nilai yang sama. Oleh karena itu, tidak mungkin untuk memilih arah terbaik.

`To Overcome Plateaus` Lakukan lompatan besar. Pilih negara yang secara acak jauh dari keadaan saat ini. Kemungkinannya adalah bahwa kita akan mendarat di wilayah non-dataran tinggi

- `Ridges` Setiap titik di punggung bukit dapat terlihat seperti puncak karena gerakan ke semua arah yang mungkin terjadi adalah ke bawah. Karenanya algoritma berhenti ketika mencapai kondisi ini.

`To Overcome Ridge` Dalam hambatan semacam ini, gunakan dua aturan atau lebih sebelum pengujian. Itu berarti bergerak ke beberapa arah sekaligus.

# 2. 4 Queen - CSP (Constraint Satisfaction Problems)
Source Code : [4queen-csp.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/4%20queen%20csp/n-queen_csp.cpp)

Dalam program dibawah ini, merupakan fungsi untuk mengecek tempat yang akan ditempati oleh queen.
```
// Function to check queens placement 
void nQueens(int k, int n){ 
	for (int i = 1;i <= n;i++){ 
		if (canPlace(k, i)){ 
			arr[k] = i; 
			if (k == n) 
				display(n); 
			else
				nQueens(k + 1, n); 
		} 
	} 
} 

```

Kemudian, setelah mengecek tempat yang akan ditempati queen, lalu fungsi program dibawah ini mengecek apakah queen aman diletakkan ditempat tersebut.
```
// Helper Function to check if queen can be placed 
bool canPlace(int k, int i){ 
	for (int j = 1;j <= k - 1;j++){ 
		if (arr[j] == i || 
			(abs(arr[j] - i) == abs(j - k))) 
		return false; 
	} 
	return true; 
} 
```

Setelah dirasa aman tempat tersebut, fungsi program dibawah ini untuk meletakkan queen pada board.
```
// Function to display placed queen 
void display(int n){ 
	breakLine 
	cout << "Arrangement No. " << ++no; 
	breakLine 
	for (int i = 1; i <= n; i++){ 
		for (int j = 1; j <= n; j++){ 
			if (arr[i] != j) 
				cout << "    X"; 
			else
				cout << "    Q"; 
		} 
		cout << endl; 
	} 
	breakLine 
} 

```

![4qcsp](https://user-images.githubusercontent.com/52326074/77139569-14d8ef00-6aa9-11ea-88c5-8cb7a395e267.png)

Tidak ada dua ratu di baris, kolom, atau diagonal yang sama.

Perhatikan bahwa ini bukan masalah optimisasi, melaikan ingin menemukan semua solusi yang mungkin, bukan satu solusi optimal, yang menjadikannya kandidat alami untuk pemrograman kendala. Bagian berikut menjelaskan pendekatan Constraint Programming untuk masalah N-queens

CP (Constraint Programming) bekerja dengan secara sistematis mencoba semua kemungkinan penugasan nilai untuk variabel dalam masalah, untuk menemukan solusi yang layak. Dalam masalah 4-queens, pemecah dimulai pada kolom paling kiri dan berturut-turut menempatkan satu ratu di setiap kolom, di lokasi yang tidak diserang oleh ratu yang sebelumnya ditempatkan.

## Propagation and backtracking

Ada dua elemen kunci untuk pencarian pemrograman kendala:
- `Propagation` - Setiap kali pemecah memberikan nilai ke variabel, kendala menambahkan batasan pada nilai yang mungkin dari variabel yang tidak ditetapkan. Pembatasan ini menyebar ke penugasan variabel masa depan. Misalnya, dalam masalah 4-queens, setiap kali pemecah menempatkan ratu, ia tidak dapat menempatkan ratu lain di baris dan diagonal ratu saat ini aktif. Propagasi dapat mempercepat pencarian secara signifikan dengan mengurangi sekumpulan nilai variabel yang harus dieksplorasi oleh pemecah.
- `Backtracking occurs` - ketika solver tidak dapat memberikan nilai ke variabel berikutnya, karena kendala, atau ia menemukan solusi. Dalam kedua kasus tersebut, pemecah melakukan backtracks ke tahap sebelumnya dan mengubah nilai variabel pada tahap itu ke nilai yang belum pernah dicoba. Dalam contoh 4-queens, ini berarti memindahkan ratu ke kotak baru pada kolom saat ini.

Dengan hipotesis ini, kendala apa yang bisa kita sebarkan? Satu kendala adalah bahwa hanya ada satu ratu dalam kolom (X abu-abu di bawah), dan kendala lain melarang dua ratu pada diagonal yang sama (X merah di bawah).

![4qcsp1](https://user-images.githubusercontent.com/52326074/77139791-f7f0eb80-6aa9-11ea-8474-4ea76873034e.png)

Kendala ketiga dilarang ratu di baris yang sama:

![4qcsp2](https://user-images.githubusercontent.com/52326074/77139793-f9221880-6aa9-11ea-8247-01dbe0430e0d.png)

Kendala diperbanyak, dapat diuji hipotesis lain, dan menempatkan ratu kedua di salah satu kotak yang tersisa. Pemecahannya mungkin memutuskan untuk menempatkan di dalamnya kotak pertama yang tersedia di kolom kedua:

![4qcsp3](https://user-images.githubusercontent.com/52326074/77139794-f9221880-6aa9-11ea-90f0-64b47585851f.png)

Setelah menyebarkan batasan diagonal, dapat dilihat bahwa itu tidak meninggalkan kotak yang tersedia di kolom ketiga atau baris terakhir:

![4qcsp4](https://user-images.githubusercontent.com/52326074/77139795-f9baaf00-6aa9-11ea-828f-f4a2cde6f04b.png)

Tanpa solusi yang memungkinkan pada tahap ini, maka perlu mundur. Salah satu opsi adalah bagi pemecah untuk memilih kuadrat lain yang tersedia di kolom kedua. Namun, propagasi kendala kemudian memaksa ratu ke baris kedua kolom ketiga, tidak meninggalkan tempat yang valid untuk ratu keempat:

![4qcsp5](https://user-images.githubusercontent.com/52326074/77139797-fa534580-6aa9-11ea-9503-e91583625389.png)

Jadi pemecah harus mundur lagi, kali ini semua jalan kembali ke penempatan ratu pertama. Sekarang telah menunjukkan bahwa tidak ada solusi untuk masalah ratu yang akan menempati kotak sudut.

Karena tidak ada ratu di sudut, pemecah memindahkan ratu pertama satu per satu, dan menyebar, hanya menyisakan satu tempat untuk ratu kedua :

![4qcsp6](https://user-images.githubusercontent.com/52326074/77139798-fa534580-6aa9-11ea-89c3-497d77960785.png)

Menyebarkan lagi mengungkapkan hanya satu tempat tersisa untuk ratu ketiga:

![4qcsp7](https://user-images.githubusercontent.com/52326074/77139799-faebdc00-6aa9-11ea-9420-03e82c5afa31.png)

Dan untuk ratu keempat dan terakhir:

![4qcsp8](https://user-images.githubusercontent.com/52326074/77139801-fb847280-6aa9-11ea-9919-ccff9a4bce2e.png)

Dapat dilihat bahwa sudah ditemukan solusi pertama! Jika ingin menginstruksikan pemecahnya untuk berhenti setelah menemukan solusi pertama, itu akan berakhir di sini. Kalau tidak, itu akan mundur lagi dan menempatkan ratu pertama di baris ketiga kolom pertama.

# 3. 8 Puzzle - BFS (Breadth First Search)
Source Code : [8puzzle-bfs.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/8%20puzzle%20bfs/8-puzzle_bfs.cpp)

BFS `(Breadth First Search)` adalah strategi sederhana di mana simpul akar diperluas terlebih dahulu, kemudian semua penerus simpul akar diperluas selanjutnya, kemudian penerusnya dan seterusnya sampai jalan terbaik yang mungkin telah ditemukan. Karena kenyataan bahwa strategi untuk grafik traversal ini tidak memiliki informasi tambahan tentang status di luar yang disediakan dalam definisi masalah, Breadth First Search digolongkan sebagai pencarian yang kurang informasi atau blind.

Breadth First Search Menggunakan struktur data `queue` sebagai lawan dari stack yang digunakan Depth First Search.

BFS menggunakan struktur data antrian yang merupakan struktur data `First In, First Out` atau FIFO. Antrian ini menyimpan semua node yang harus kita jelajahi dan setiap kali sebuah node dieksplorasi ditambahkan ke set node yang dikunjungi.

Jika dilakukan pencarian luas pertama di pohon biner di atas maka itu akan melakukan hal berikut:
- Tetapkan Node 1 sebagai Node awal
- Tambahkan Node ini ke queue
- Tambahkan Node ini ke set yang dikunjungi
- Jika node ini adalah node tujuan kami, maka kembalikan benar, kalau tidak tambahkan Node 2 dan Node 3 ke queue
- Periksa Node 2 dan jika itu tidak menambahkan Node 4 dan Node 5 ke queue
- Ambil node berikutnya dari queue yang seharusnya Node 3 dan periksa
- Jika Node 3 bukan node tujuan kami tambahkan Node 6 dan Node 7 ke queue
- Ulangi sampai Node sasaran ditemukan.

Jika dilakukan penghentian eksekusi setelah Node 3 diperiksa, maka queue akan terlihat Node 4, Node 5, Node 7, Node 8.

Seperti yang pada gambardibawah ini, jika mengikuti algoritma ini maka akan secara rekursif mencari setiap tingkat pohon biner menjadi lebih dalam dan lebih dalam sampai Anda menemukan jalan terpendek yang mungkin.

![bfs](https://user-images.githubusercontent.com/52326074/77224197-c1909a80-6b95-11ea-92fa-ccdca09a36ac.png)

# 4. 8 Puzzle - DFS (Depth First Search)
Source Code : [8puzzle-dfs.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/8%20puzzle%20dfs/8-puzzle_dfs.cpp)

Algoritma DFS `Depth First Search` adalah algoritma rekursif yang menggunakan gagasan backtracking. Ini melibatkan pencarian lengkap dari semua node dengan melanjutkan, jika mungkin, dengan mundur.

Depth First Search Menggunakan struktur data `stack` sebagai lawan dari queue yang digunakan Breadth First Search.

Di sini, kata mundur berarti bahwa ketika pencarian bergerak maju dan tidak ada lagi node di sepanjang jalur saat ini, pencarian bergerak mundur di jalur yang sama untuk menemukan node untuk dilintasi. Semua node akan dikunjungi di jalur saat ini sampai semua node yang belum dikunjungi telah dilalui setelah jalur berikutnya akan dipilih.

Sifat rekursif DFS ini dapat diimplementasikan menggunakan tumpukan. Ide dasarnya adalah sebagai berikut:
- Pilih simpul awal dan dorong semua simpul yang berdekatan ke tumpukan.
- Pop sebuah node dari stack untuk memilih node berikutnya untuk mengunjungi dan mendorong semua node yang berdekatan ke dalam stack.
- Ulangi proses ini sampai tumpukan kosong. Namun, pastikan bahwa node yang dikunjungi ditandai. Ini akan mencegah Anda mengunjungi simpul yang sama lebih dari sekali. Jika Anda tidak menandai node yang dikunjungi dan Anda mengunjungi node yang sama lebih dari sekali, Anda mungkin berakhir dalam loop tak terbatas.

![dfs](https://user-images.githubusercontent.com/52326074/77224296-cace3700-6b96-11ea-9dc1-810524ec907a.jpg)

# 5. 8 Puzzle - IDS (Iterative Deepening Search)
Source Code : [8puzzle-ids.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/8%20puzzle%20ids/8-puzzle_ids.cpp)

`Iterative Deepening Search` (IDS) merupakan sebuah strategi umum yang biasanya dikombinasikan dengan Depth First tree search, yang akan menemukan berapa depth limit terbaik untuk digunakan. Hal ini dilakukan dengan secara menambah limit secara bertahap, mulai dari 0,1, 2, dan seterusnya sampai goal sudah ditemukan.

![ids](https://user-images.githubusercontent.com/52326074/77226305-dd05a080-6ba9-11ea-8a8e-4216c8be6935.png)

Iterative Deepening DFS dengan kata-kata sederhana menjalankan DFS dengan secara bertahap meningkatkan batas kedalaman - 0, kemudian mengulangi DFS dari awal dengan batas kedalaman 1, kemudian mengulangi DFS dari awal dengan tingkat kedalaman 2, dan seterusnya, hingga solusi ditemukan . Jadi bagaimana ini menggabungkan manfaat DFS dan BFS?

Ini memiliki persyaratan memori sederhana seperti DFS yaitu O (bm)

Sejak menjalankan DFS (meskipun dengan meningkatkan level kedalaman dengan setiap iterasi), persyaratan memorinya akan sama dengan DFS.

Ini optimal asalkan biaya jalur adalah fungsi nececreasing dari kedalaman node, seperti BFS. Karena Anda mengulangi strategi DFS dengan meningkatkan batas kedalaman dengan setiap iterasi, Anda dapat yakin bahwa Anda melintasi saudara kandung leluhur Anda dalam iterasi sebelumnya yang pada gilirannya menjamin bahwa tidak ada keadaan solusi yang ada pada level yang lebih dangkal.

Lengkap seperti BFS asalkan faktor percabangannya terbatas. Karena itu melintasi lebar juga - karena Anda mengulangi DFS dengan tingkat kedalaman yang meningkat - itu tidak bisa terjebak pada jalur yang tak terbatas.

# 6. 8 Puzzle - Heuristic
Source Code : [8puzzle-heuristic.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/8%20puzzle%20heuristic/8-puzzle-heuristic.cpp)

Dalam program ini diminta untuk menyelesaikan 8 puzzle menggunakan metode heuristic 1 dan 2. Dimana penjelasan heuristic 1 dan 2 ada dibawah. Jika menggunakan heuristic 1 maka yang dilihat yaitu banyaknya grid yang menempati tempat yg salah, tetapi jika menggunakan heuristic 2 maka yang dilihat yaitu total keseluruhan jarak tiap grid yang menempati tempat yang salah terhadap posisi grid yang benar, atau sering disebut dengan manhattan distance.

Jadi dalam penyelesainnya kita mengeluarkan hasil setiap langkah puzzle dengan melihat penempatan grid yang salah kemudian dicari penempatan grid yang benar untuk mencapai final state yang diinginkan.

Dalam program ini, penyelesaian dengaan menggunakan tree, seperti pada gmbar dibawah nantinya.
```
struct Node { 
	// stores the parent node of the current node helps in tracing path when the answer is found 
	Node* parent; 
	// stores matrix 
	int mat[N][N]; 
	// stores blank tile coordinates 
	int x, y; 
	// stores the number of misplaced tiles 
	int cost; 
	// stores the number of moves so far 
	int level; 
}; 
```

Kemudian setiap langkah pastinya memerlukan node untuk meletakkan grid nya, maka dari itu program dibawah ini untuk meyediakan node setiap langkah.
```
Node* newNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) { 
	Node* node = new Node; 
	// set pointer for path to root 
	node->parent = parent; 
	// copy data from parent node to current node 
	memcpy(node->mat, mat, sizeof node->mat); 
	// move tile by 1 position 
	swap(node->mat[x][y], node->mat[newX][newY]); 
	// set number of misplaced tiles 
	node->cost = INT_MAX; 
	// set number of moves so far 
	node->level = level; 
	// update new blank tile cordinates 
	node->x = newX; 
	node->y = newY; 
	return node; 
} 
```

Karena heuristic ini melihat posisi grid yang salah, maka fungsi program dibawah ini untuk menghitung banyak nya angka yang tidak sesuai dengan final state.
```
int calculateCost(int initial[N][N], int final[N][N]) { 
	int count = 0; 
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (initial[i][j] && initial[i][j] != final[i][j]) 
				count++; 
	return count; 
} 
```

Untuk bagian dibawah ini adalah pergerakan puzzle yang dimisalkan dengan `botton, left, top, right`
```
int row[] = { 1, 0, -1, 0 }; 
int col[] = { 0, -1, 0, 1 }; 
```

Setelah itu, fungsi dibawah ini untu megecek apakah posisi grid dimana angka didalamnya sudah sesuai dengan final statenya.
```
int isSafe(int x, int y) { 
	return (x >= 0 && x < N && y >= 0 && y < N); 
} 
```

Semua fungsi dijalankan dalam fungsi dibawah ini dimana untuk mengecek solusi penyelesaian menggunakan heuristic dengan initial awal puzzle yang dimasukkan kemudian final state yang diinginkan.
```
void solve(int initial[N][N], int x, int y, int final[N][N]) { 
	// Create a priority queue to store live nodes of search tree; 
	priority_queue<Node*, std::vector<Node*>, comp> pq; 
	// create a root node and calculate its cost 
	Node* root = newNode(initial, x, y, x, y, 0, NULL); 
	root->cost = calculateCost(initial, final); 
	// Add root to list of live nodes; 
	pq.push(root); 
	// Finds a live node with least cost, add its childrens to list of live nodes and 
	// finally deletes it from the list. 
	while (!pq.empty()) { 
		// Find a live node with least estimated cost 
		Node* min = pq.top(); 
		// The found node is deleted from the list of live nodes 
		pq.pop(); 
		// if min is an answer node 
		if (min->cost == 0) { 
			// print the path from root to destination; 
			printPath(min); 
			return; 
		} 
		// do for each child of min, max 4 children for a node 
		for (int i = 0; i < 4; i++) { 
			if (isSafe(min->x + row[i], min->y + col[i])) { 
				// create a child node and calculate its cost 
				Node* child = newNode(min->mat, min->x, 
							min->y, min->x + row[i], 
							min->y + col[i], 
							min->level + 1, min); 
				child->cost = calculateCost(child->mat, final); 

				// Add child to list of live nodes 
				pq.push(child); 
			} 
		} 
	} 
} 
```

![8p](https://user-images.githubusercontent.com/52326074/77151801-52e60b00-6ac9-11ea-84f6-e27a66305731.png)

8-puzzle adalah puzzle yang ditemukan dan dipopulerkan oleh Noyes Palmer Chapman pada tahun 1870-an. Ini dimainkan pada kotak 3-oleh-3 dengan 8 blok persegi berlabel 1 hingga 8 dan kotak kosong. Tujuan Anda adalah mengatur ulang blok agar sesuai. Anda diizinkan untuk menggeser blok secara horizontal atau vertikal ke dalam kotak kosong. Berikut ini menunjukkan urutan langkah hukum dari posisi dewan awal (kiri) ke posisi tujuan (kanan).

8-Puzzle merupakan salah satu jenis permainan puzzle dimana kita harus mencapai goal puzzle dari initial puzzle yang diberikan. Untuk mencapai goal puzzle, 8-puzzle ini menyediakan satu grid kosong agar grid-grid lain disekitarnya dapat digerakkan. Sebagai contoh Inisial State dan Goal State dari sebuah puzzle adalah :

![8ph](https://user-images.githubusercontent.com/52326074/77028971-f9001b00-69cc-11ea-9301-6be95c8f1df1.PNG)

Pada pembahasan kali ini, saya ingin menyelesaikan puzzle ini dengan suatu algoritma, yaitu Algoritma Greedy, dengan menggunakan dua fungsi heuristik. Algoritma Greedy merupakan algoritma yang sederhana dan lempeng (straightforward). Secara harfiah greedy artinya rakus atau tamak.

Algoritma Greedy membentuk solusi langkah per langkah. Terdapat banyak pilihan yang perlu dieksplorasi pada setiap langkah solusi. Oleh karena itu, pada setiap langkah harus dibuat keputusan yang terbaik dalam menentukan pilihan. 

Dalam bahasan ini, fungsi heuristik yang akan kita tampilkan yaitu adalah sebagai berikut.
- h₁(n) : sebagai banyak grid yang menempati tempat yang salah.
- h₂(n) : sebagai total keseluruhan jarak tiap grid yang menempati tempat yang salah terhadap posisi grid yang benar, atau sering disebut dengan manhattan distance.

Solusi Penyelesaian dengan fungsi Heuristik Pertama yaitu banyak grid yang menempati tempat yang salah

![8puzzle-heuristic1.1](https://user-images.githubusercontent.com/52326074/77029102-58f6c180-69cd-11ea-9571-7a69fe89de7d.PNG)
![8puzzle-heuristic1.2](https://user-images.githubusercontent.com/52326074/77029100-585e2b00-69cd-11ea-8d32-03512709f26c.PNG)
![8puzzle-heuristic1.3](https://user-images.githubusercontent.com/52326074/77029097-572cfe00-69cd-11ea-845e-7e8b50514214.PNG)

Solusi :
Initial State -> Right -> Up -> Right -> Down -> Down -> Left -> Up -> Right -> Down(Goal)

Solusi Penyelesai dengan fungsi Heuristik Kedua yaitu total keseluruhan jarak tiap grid yang menempati tempat yang salah terhadap posisi grid yang benar, atau sering disebut dengan manhattan distance.

![8puzzle-heuristic2.1](https://user-images.githubusercontent.com/52326074/77029181-8f344100-69cd-11ea-9799-24cda528fdd5.PNG)
![8puzzle-heuristic2.2](https://user-images.githubusercontent.com/52326074/77029178-8e9baa80-69cd-11ea-9d35-2282c1916e48.PNG)
![8puzzle-heuristic2.3](https://user-images.githubusercontent.com/52326074/77029175-8d6a7d80-69cd-11ea-8775-2fd302b4ad62.PNG)

Solusi :
Initial State -> Right -> Up -> Right -> Down -> Down -> Left -> Up -> Right -> Up(Goal)


Kesimpulannya, dari semua yang telah dipaparkan diatas, penggunaan dari dua fungsi heuristik Algoritma Greedy pada solusi penyelesaian 8-puzzle, baik fungsi heuristik pertama dan kedua sama sama mampu memberikan solusi penyelesaian dari awal state sampai ke goal state. Tetapi menurut pendapat saya, pada penggunaan fungsi heuristik pertama jumlah State puzzle yang memiliki fungsi heuristik yang sama lebih banyak dari pada penggunaan fungsi heuristik kedua. Jadi, penggunaan solusi dari fungsi heuristik kedua dalam contoh penyelesaian 8-puzzle diatas lebih optimal dari pada fungsi heuristik pertama.

# 7. Minimax - Tic Tac Toe
Source Code : [minimax-tictactoe.cpp](https://github.com/daffaaflah6/KB-F_05111840000030/blob/master/Minimax%20tictactoe/minimax.cpp)

Dalam permasalahan minimax, selain menentukan nilai min maupun max dalam sekelompok angka, namun juga bisa diaplikasikan dalam penyelesaian tic tac toe game. Pastinya dalam menjalankan permainan ini, dilakukan secara bergiliran untuk meletakkan karakter pada kolom yang disediakan.

Pada bagian dibawah ini untuk mendeteksi pada kolom apakah sudah terisi karakter `X` atau `O` atau bahkan kosong ` `.
```
char gridChar(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}
```

Untuk bagian dibawah ini, mencetak board tic tac toe.
```
void draw(int b[9]) {
    printf(" %c | %c | %c\n",gridChar(b[0]),gridChar(b[1]),gridChar(b[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[3]),gridChar(b[4]),gridChar(b[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n",gridChar(b[6]),gridChar(b[7]),gridChar(b[8]));
}
```

Kemudian, fungsi program dibawah ini untuk mengecek setelah player melakukan langkah / mengisi karakter pada board itu mencapai kemenangan (sudah terbentuk garis).
```
int win(const int board[9]) {
    //determines if a player has won, returns 0 otherwise.
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}
```

Sedangkan untuk bagian dibawah ini, untuk berjalannya tic tac toe dengan mengecek perpindahan player meletakkan karakter pada board dengan menggunakan metode minimax.
```
int minimax(int board[9], int player) {
    //How is the position like for player (their turn) on board?
    int winner = win(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 0; i < 9; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}
```

Bagian dibawah ini untuk lawan / dalam hal ini dibuat computer sebagai lawan untuk berjalan menentukan letak karakter.
```
void computerMove(int board[9]) {
    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    board[move] = 1;
}
```

Sedangkan bagian dibawah ini untuk player utama berjalan menentukan letak karakter.
```
void playerMove(int board[9]) {
    int move = 0;
    do {
        printf("\nInput move ([0..8]): ");
        scanf("%d", &move);
        printf("\n");
    } while (move >= 9 || move < 0 && board[move] == 0);
    board[move] = -1;
}
```

Tic Tac Toe merupakan permainan yang dimainkan oleh 2 pemain dengan menempatkan ‘buah’ yang berlainan untuk tiap pemain pada kotak 3 x 3. Penempatan ‘buah’ dilakukan secara bergantian sehingga salah satu pemain menjadi pemenang atau seluruh kotak terisi oleh ‘buah’. Salah satu pemain dikatakan menang jika dapat menempatkan ‘buah’ berjajar sebanyak 3 buah baik secara horisontal, vertikal atau diagonal.

Dalam permainan ini kita harus berusaha untuk memaksimalkan kemungkinan untuk mencapai kemenangan pemain pertama dan meminimalkan kemungkinan kemenangan lawan (pemain kedua).

Komponen penelusuran dalam aplikasi minimax pada permainan Tic Tac Toe ini adalah :

- `Initial state` merupakan keadaan saat pencarian akan dilakukan, pada saat permainan mulai dilakukan (jika pemain pertama jalan pertama), initial statenya adalah :

![tictactoe.1](https://user-images.githubusercontent.com/52326074/77034748-4dab9200-69dd-11ea-8215-48c660f28237.JPG)

Initial state selalu berubah saat giliran jalan pemain pertama.
- `Operator (rule/ilegal moves)`, Operator pada permainan ini adalah pemain dapat meletakkan ‘buah’ nya secara sembarang di kotak yang masih kosong.
- `Terminal Test` adalah keadaan dimana komposisi terbaik yang dilakukan pemain pertama setelah diadakan penelusuran.
- `Utility function` pada permainan ini adalah mencari kemungkinan kemenangan bagi pemain pertama dikurangi dengan kemungkinan kemenangan dari pemain lawan. Pada saat permainan dimulai masing-masing kemungkinan kemenangan tiap pemain adalah 8 yaitu 3 horisontal + 3 vertikal + 2 diagonal.

![tictactoe.2](https://user-images.githubusercontent.com/52326074/77034890-b561dd00-69dd-11ea-9a93-b8adca75b3e8.JPG)

Contoh pada komposisi :

![tictactoe.3](https://user-images.githubusercontent.com/52326074/77034911-c4488f80-69dd-11ea-904e-87b6294917db.JPG)

Kemungkinan kemenangan pemain pertama adalah 6, sedangkan kemungkinan kemenangan pemain kedua adalah 5.

![tictactoe.4](https://user-images.githubusercontent.com/52326074/77034938-d88c8c80-69dd-11ea-845c-596e936eaad9.JPG)

Jadi nilai untuk komposisi di atas adalah 6 – 5 = 1.

Dari keadaan permainan dimulai, graph minimax untuk Two-Ply Search dapat digambarkan sebagai berikut (X = pemain pertama, O = pemain kedua):

![tictactoe.5](https://user-images.githubusercontent.com/52326074/77034975-efcb7a00-69dd-11ea-97ae-2ff5b0943d04.JPG)

Nilai node E sampai P didapat dari utility function yang telah didefinisikan sebelumnya sehingga didapatkan :
```
E = 6 – 5 = 1
F = 5 – 5 = 0
G = 6 – 5 = 1
H = 5 – 5 = 0
I = 4 – 5 = -1
J = 5 – 4 = 1
K = 6 – 4 = 2
L = 5 – 6 = -1
M = 5 – 5 = 0
N = 5 – 6 = -1
O = 6 – 6 = 0
P = 4 – 6 = -2
```

Ada sembilan langkah yang mungkin dilakukan oleh pemain pertama karena kotak kosongnya berjumlah 9, tapi pada diagram diatas hanya diambil 3 kemungkinan (node B,C dan D), karena 6 kemungkinan lainnya setara dengan ke-3 komposisi di atas, misalnya :

![tictactoe.6](https://user-images.githubusercontent.com/52326074/77035007-083b9480-69de-11ea-9932-0b194195291b.JPG)

Dari node B seharusnya didapatkan node anak sebanyak 8 node, dengan mengabaikan node yang setara node anak dari B menjadi E, F, G, H dan I. Dengan cara yang sama didapatkan node anak dari C yaitu J dan K, sedangkan node anak dari D yaitu L, M, N, O dan P.

Karena hanya menggunakan Two-Ply Search, node-node anak dari B, C dan D dicari nilainya, kemudian dicari yang terkecil (min) masing-masing untuk dijadikan nilai B, C dan D. Selanjutnya dicari nilai terbesar (max) dari ketiga nilai tersebut untuk menentukan langkah pemain pertama.

Pada diagram yang digambarkan diatas, node anak dari B bernilai masing-masing E=1, F=0, G=1, H=0 dan I=-1 jadi nilai B diambil yang terkecil yaitu –1.

Node anak dari C bernilai masing-masing J=1 dan K=2 jadi nilai C diambil yang terkecil yaitu 1. Kemudian node anak dari D bernilai masing-masing L=-1, M=0, N=-1, O=0 dan P=-2 jadi nilai C diambil yang terkecil yaitu –2.

Selanjutnya dari nilai node B=-1, C=1, dan D=-2 diambil nilai terbesar yaitu C=1, yang berarti langkah terbaik yang harus dilakukan oleh pemain pertama adalah node C.

Setelah pemain kedua menempatkan buahnya, keadaan saat itu dijadikan initial state dan dilakukan kembali pelacakan dengan langkah yang telah dijelaskan di atas. Contoh : Misalkan pemain kedua meletakkan buahnya seperti gambar berikut :

![tictactoe.7](https://user-images.githubusercontent.com/52326074/77035046-21444580-69de-11ea-89a1-5eeb2dd345c4.JPG)

Dari keadaan ini, graph minimax untuk Two-Ply Search dapat digambarkan sebagai berikut (X = pemain pertama, O = pemain kedua):

![tictactoe.8](https://user-images.githubusercontent.com/52326074/77035066-2e613480-69de-11ea-816d-f67b069d2523.JPG)

Dari diagram diatas, langkah terbaik yang dapat dilakukan oleh pemain pertama terdapat dua pilihan yaitu B(1) dan D(1).

# 8. Wumpus World Game
