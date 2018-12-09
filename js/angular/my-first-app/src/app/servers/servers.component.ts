import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-servers',
  templateUrl: './servers.component.html',
  styleUrls: ['./servers.component.css']
})
export class ServersComponent implements OnInit {
allowNewServer = false;
serverStatus = 'no server created!';
serverName = '';
serverCreated = false;
servers = ['test1','test2'];
  constructor() {
    setTimeout(()=>{
      this.allowNewServer = true;
    },2000)
   }

  ngOnInit() {
  }

  onCreateServer(){
    this.servers.push(this.serverName);
    this.serverCreated = true;
    this.serverStatus = 'Server was created and its name is '+ this.serverName;
  }

  getServerName(event: any){
    this.serverName = event.target.value;
  }

}
