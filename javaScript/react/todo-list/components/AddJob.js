import React, { Component } from 'react';

export class AddJob extends Component {
    shouldComponentUpdate(newProps, newState){
        if(this.props.data === newProps.data){
          return false;
        }
        return true;
    }
    render() {
        console.log('AddJob render')
        return(
            <>
                <form 
                    action="/add_job" method="post"
                    onSubmit={function(e){
                        e.preventDefault();
                        this.props.onSubmit(
                            e.target.job.value
                        );
                    }.bind(this)}
                >
                <p>
                 <input type="text" name="job"
                 placeholder="Thing to do"></input>
                 <input type="submit" value="add"></input>
                </p>
                </form>
            </>
        );
    }
}