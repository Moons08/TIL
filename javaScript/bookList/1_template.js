const templateSource   = `
  <div class="row">
    <div class="col-12">
      <input type="text" name="todo" class="form-control" placeholder="할 일을 입력하세요">
    </div>
    <div class="col-12">
      <ul class="list-group">

        {{#each todos}}
        <li class="list-group-item list-group-flat">
          <div class="checkbox">
            <input type="checkbox" id="todo-status-{{id}}" value="{{id}}">
            <label for="todo-status-{{id}}">{{todo}}</label>
            <button type="button" name="delete" class="btn btn-outline-secondary btn-sm" data-id="{{id}}">X</button>
          </div>
        </li>
        {{/each}}
      </ul>      
    </div>            
  </div>
  <div class="col-12 todo-status"> 
    할 일:<span>{{allTodos}}건</span>
    완료:<span>{{completeTodo}}건</span>
    미완료:<span>{{incompleteTodo}}건</span>  
  </div>        
`;
// debugger;
let template = Handlebars.compile(templateSource);

let TodoApp = {
  todos: [], // 할 일 목록
  el: [],

  
  start() {
    this.container = document.querySelector('.container');
    // 비동기로 이벤트 걸어놓음
    this.container.addEventListener('keypress', this.onCreateTodo.bind(this));
    this.container.addEventListener('click', this.onDeleteTodo.bind(this));
    this.container.addEventListener('change', this.onChangeStatus.bind(this));

    this.updateView();
    // console.log(this.todos);
  },

  add(title) {
    this.todos.push({
      id: Date.now(),
      todo: title,
      complete: false,
      createDate: new Date(),
      dueDate: null,
      completeDate: null
    });
  },

  updateView() {
    this.container.innerHTML = template({ todos: this.todos
                                    , allTodos: this.todos.length
                                    , incompleteTodo: this.todos.length
                                     });
  },

  onCreateTodo(event) {
    if (event.target.name === 'todo') {
      if (event.which === 13) {
        this.add(event.target.value);
        this.updateView();
      }
    }
  },

  onDeleteTodo(event) {
    if (event.target.name === 'delete' && event.target.checked ) {
        let id = event.target.dataset.id;
        console.log(id)
        // x 누른 애 말고 나머지만 리턴
        this.todos = this.todos.filter(todo => todo.id != id); 
        
        this.updateView();
    }
  },

  // 체크박스인 경우만 동작하게 만들기
  // 체크박스 체인지 되어있는 요소 체크 가능?
  onChangeStatus(event) {
        console.log(event.target.checked)
  }
};

TodoApp.start();