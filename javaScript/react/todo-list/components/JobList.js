import React, { Component } from 'react';

export class JobList extends Component {
    shouldComponentUpdate(newProps, newState){
        if(this.props.data === newProps.data){
            return false;
        }
        return true;
      }
    checkHandler(e){
        let _data = Array.from(this.props.data);
        for (let i=0; i< _data.length; i++) {
            if (_data[i].id === Number(e.target.value)
            && _data[i].checked !== e.target.checked) {
                _data[i].checked = e.target.checked
            }
        }
        this.setState({data:_data})
    }
    render() {
        let jobs = [];
        let data = this.props.data
        for (let i=0; i < data.length; i++){
            jobs.push(
                <li key={data[i].id}>
                    {data[i].todo}
                    <input
                        type="checkbox"
                        name="todo"
                        value={data[i].id}
                        checked={data.checked}
                        onChange={this.checkHandler.bind(this)}
                    ></input>
                </li>
            )
        }
        return(
            <>
                <h2>To-Do List</h2>
                {jobs}
                <br/>
            </>
        );
    }
}