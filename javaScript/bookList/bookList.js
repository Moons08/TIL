const container = document.querySelector('#books')
const btnSort = document.querySelector('#btn-sort')
const promise = fetch('/api/books')
let books = []

const uiHandler = response => {
    // 비동기 응답 받아서 변수 저장 후 테이블 그리는 함수 호출
    books = response;
    uiUpdate();
}

const uiUpdate = () => {
    // 목록 테이블 그리는 함수
    let bookList = books.map(data => {
        return `
        <tr>
            <td>${data.title}</td>
            <td>${data.writer}</td>
            <td>${data.publisher}</td>
            <td>${data.price}</td>
        </tr>
        `
    });

    container.innerHTML = `
    <table border='1'>
        <thead>
            <tr>
                <td>title</td>
                <td>writer</td>
                <td>publisher</td>
                <td>price</td>
            </tr>
        </thead>
        <tbody>
            ${bookList.join('')}
        </tbody>
    </table>
    `
}

promise
    .then(response=>response.json()
    .then(uiHandler))
    .catch(err=>console.log(err))


// btn control
let sortState = 0

const priceSort = () => {
    // 정렬 버튼 누를때마다 가격 정렬 순서 변경
    // 정렬 후 테이블 그리는 함수 호출
    if (sortState) {
        books = books.sort(sort);
        sortState++;
    } else {
        books = books.sort(reverseSort);
        sortState--;
    }
    uiUpdate();
}
const sort = (a, b) => {
    a = a.price
    b = b.price
    if (a>b) return 1;
    else if (a==b) return 0;
    else return -1;
};
const reverseSort = (a, b) => sort(b, a);

btnSort.addEventListener('click', priceSort)
