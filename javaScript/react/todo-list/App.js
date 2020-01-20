import React, { Component } from 'react';
import { JobList } from './components/JobList'; 
import { AddJob } from './components/AddJob'; 
import './App.css';

class App extends Component {
  constructor(props) {
    super(props);
    this.state={
      max_content_id: 2,
      data: [
        {id:0, todo:'sample1', checked:false},
        {id:1, todo:'sample2', checked:false},
        {id:2, todo:'sample3', checked:false},
      ]
    }
  }

  add(_todo){
    let _max_content_id = this.state.max_content_id + 1
    let _data = Array.from(this.state.data);
    _data = _data.concat(
      {id:_max_content_id,
       todo: _todo,
       checked: false}
    )
    this.setState({
      data:_data,
      max_content_id:_max_content_id
    })
  }

  delete(){
    if (window.confirm('really?')) {
      let _data = Array.from(this.state.data);
      this.setState({
        data: _data.filter(data => data.checked !== true)
      })
    }
  }

  render() {
  return (
      <div className="App">
        <JobList data={this.state.data}></JobList>

        <AddJob onSubmit={this.add.bind(this)}></AddJob>

        <input 
          type='button'
          value='remove'
          onClick={this.delete.bind(this)}>
        </input>
      </div>
    );
  }
}
export default App;
