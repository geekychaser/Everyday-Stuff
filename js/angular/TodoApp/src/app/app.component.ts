import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'todos';
  content = '';
  lists = [];

  getContent(event: any) {
    this.content = event.target.value;
  }
  addToList() {
    this.lists.push(this.content);
  }
}
