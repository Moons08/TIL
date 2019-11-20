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
            <input type="checkbox" id="todo-status-{{id}}" value="{{id}}"{{#if complete}} checked{{/if}}>
            <label for="checkbox">{{todo}}</label>
            <button type="button" name="delete" class="btn btn-outline-secondary btn-sm" data-id="{{id}}">X</button>
          </div>
        </li>
        {{/each}}
      </ul>      
    </div>            
  </div>
  <div class="col-12 todo-status">
    전체:<span data-bind="allTodos" data-bind-render="bolder"></span>
    완료:<span data-bind="completeTodo" data-bind-render="counter"></span>
    미완료:<span data-bind="incompleteTodo" data-bind-render="counter"></span>  
  </div>
`;

const renderPlugins = {
  text(value) {
    return String(value);
  },

  bolder(value) {
    return `<strong>${value}</strong>`;
  },

  counter(value) {
    return `${value}건`;
  }
};