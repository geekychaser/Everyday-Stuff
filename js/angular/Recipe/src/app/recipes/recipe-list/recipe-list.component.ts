import { Component, OnInit } from '@angular/core';
import { Recipe } from '../recipe.model';

@Component({
  selector: 'app-recipe-list',
  templateUrl: './recipe-list.component.html',
  styleUrls: ['./recipe-list.component.css']
})
export class RecipeListComponent implements OnInit {

  recipes: Recipe[] = [
    new Recipe('test recipe', 'this is test recipe description', 'https://goo.gl/6SGwCb'),
    new Recipe('test recipe', 'this is test recipe description', 'https://goo.gl/6SGwCb')

  ];



  constructor() { }

  ngOnInit() {
  }

}
