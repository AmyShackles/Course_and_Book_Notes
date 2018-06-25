import React, { Component } from 'react'
import './App.css';

const ReactMarkDown = require('react-markdown')
const authI = require('./Authentication/Auth-I.md');
const authII = require('./Authentication/Auth-II.md')
const auth = require('./Authentication/Authentication.md')
const docker = require('./DevOps/CS5DockerRunDown.md')
const heroku = require('./DevOps/CS5HerokuCrashCourse.md')


class App extends Component {
  constructor(props) {
    super(props)
    this.state = { 
      authI: null,
      authII: null,
      auth: null,
      docker: null,
      heroku: null,
      ngrok: null,
      gcp: null,
      devOps: null,
      mongoI: null,
      mongoII: null,
      mongoIII: null,
      mongoIV: null,
      ms101: null,
      clientI: null,
      clientII: null,
      server: null
  }
}
  componentWillMount() {
    fetch(authI).then((authI) => authI.text()).then((text) => {
      this.setState({ authI: text })
    })
    fetch(authII).then((authII) => authII.text()).then((authIItext) => {
      this.setState({ authII: authIItext })
    })
    fetch(auth).then((auth) => auth.text()).then((authtext) => {
      this.setState({ authII: authtext })
    })
    fetch(docker).then((docker) => docker.text()).then((dockertext) => {
      this.setState({ docker: dockertext })
    })
    fetch(heroku).then((heroku) => heroku.text()).then((herokutext) => {
      this.setState({ heroku: herokutext })
    })
}

  render() {
    return (
      <div className="AuthINotes">
        <ReactMarkDown source={this.state.authI} />
      </div>
    );
  }
}


export default App;
